#include "WordRepository.hpp"
#include "KanjiRepository.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"
#include "FuckWindows.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>

WordRepository * WordRepository::wordRepository = nullptr;

WordRepository * WordRepository::getInstance()
{
    if(wordRepository == nullptr) {
        wordRepository = new WordRepository;
        wordRepository->loadAllWords();
    }
    return wordRepository;
}

void WordRepository::classifyWords(){

    // Open the words file
    std::wfstream file("files/words.txt");

    if(!file.is_open()){
        std::cerr << "ERROR: file " << "files/words.txt not found" << std::endl;
        exit(EXIT_FAILURE);
    }

    file.imbue(std::locale("C.UTF-8"));

    // Open new words file
    std::wfstream newFile("files/newWords.txt",std::fstream::out);

    newFile.imbue(std::locale("C.UTF-8"));

    std::set<std::wstring> classifiedWords;

    std::map<int,std::wfstream> realFiles;
    for(int i=1;i<6;i++){
        realFiles[i].open("files/JLPTN"+std::to_string(i)+"words.txt",std::fstream::out);
        realFiles[i].imbue(std::locale("C.UTF-8"));
    }

    std::wstring data;

    // Line that should be a kanji meaning (or "#")
    getline(file,data);

    while(data != L"#"){

        // If the word is repeated...
        if(classifiedWords.count(data)){
            // Skip the line for the pronunciation
            getline(file,data);
            // Skip the line for the meaning
            getline(file,data);
            // Skip the separator line
            getline(file,data);
            // Get the next word
            getline(file,data);
            // Continue to the next iteration
            continue;
        } else {
            classifiedWords.insert(data);
        }

        newFile << data << L"\n";

        int minGrade = 5;

        for(wchar_t kanji : data){
            // Transform the wchar_t into a hash_t because a kanji is just one character
            Kanji k = KanjiRepository::getInstance()->getKanji(util::hash(std::wstring(1,kanji)));
            if(k.getKanji() == L"")
                continue;

            int currentGrade = k.getGrade();
            if(currentGrade < minGrade)
                minGrade = currentGrade;
        }

        Word w;

        w.setGrade(minGrade);

        realFiles[minGrade] << data << L"\n";

        w.setWord(data);

        // Read the pronunciation
        getline(file,data);
        newFile << data << L"\n";

        realFiles[minGrade] << data << L"\n";

        w.setPronunciation(data);

        // Read the meaning
        getline(file,data);
        newFile << data << L"\n";

        realFiles[minGrade] << data << L"\n";

        w.setMeaning(data);

        // Read a line that contains "----"
        getline(file,data);
        newFile << data << L"\n";

        realFiles[minGrade] << data << L"\n";

        // Read another word or "#"
        getline(file,data);
    }

    newFile << L"#";

    for(auto &pair : realFiles){
        pair.second << L"#";
        pair.second.close();
    }

    file.close();
    newFile.close();
}

// Operation that loads all words and progress for words
void WordRepository::loadAllWords(){

    #ifdef __linux__
    classifyWords();
    #endif

    for(int i=1;i<=5;i++){

        // Open the words file
        #ifdef __linux__
        std::wfstream file("files/JLPTN"+std::to_string(i)+"words.txt");

        if(!file.is_open()){
            std::cerr << "ERROR: file " << "files/JLPTN"+std::to_string(i)+"words.txt not found" << std::endl;
            exit(EXIT_FAILURE);
        }

        file.imbue(std::locale("C.UTF-8"));

        #else
        std::wstringstream file(FuckWindows::wordsForWindows[i]);
        #endif
        std::wstring data;

        // Line that should be a word (or "#")
        getline(file,data);

        while(data != L"#"){

            hash_t hashCode = util::hash(data);

            Word w;

            w.setGrade(i);

            w.setWord(data);

            // Read the pronunciation
            getline(file,data);

            w.setPronunciation(data);

            // Read the meaning
            getline(file,data);

            w.setMeaning(data);

            // Read a line that contains "----"
            getline(file,data);

            // Read another word or "#"
            getline(file,data);

            w.setMeaningProgress(-1);
            w.setPronunciationProgress(-1);

            if(!words.count(hashCode)) {
                newWords[i].push_back(hashCode);
            } else {
                std::wcerr << "WARNING: Found hash collision between words " << w.getMeaning() << " and " << words[hashCode].getMeaning() << " (" << hashCode << ")" << std::endl;
            }

            words[hashCode] = w;
        }

        #ifdef __linux__
        file.close();
        #endif

        // Open the progress file
        std::wfstream fileprogress("save/JLPTN"+std::to_string(i)+"wordprogress.txt");

        if(!fileprogress.is_open()){
            // The file doesn't exist: let's create it
            fileprogress.open("save/JLPTN"+std::to_string(i)+"wordprogress.txt",std::fstream::out);

            for(hash_t hashCode : newWords[i]){
                fileprogress << hashCode << "\n-1\n-1\n";
                words[hashCode].setPronunciationProgress(-1);
                words[hashCode].setMeaningProgress(-1);
            }

            fileprogress << "#";

        } else {

            // First line, can be a "#" or a word containing kanji
            getline(fileprogress,data);

            while(data != L"#"){

                hash_t hashCode = std::stoul(data);

                if(!words.count(hashCode))
                    std::wcerr << "WARNING: In grade " << i << " found saved data for word with hash code " << hashCode << " but no word was found" << std::endl;

                // Get the word and assign it the progress numbers
                Word &w = words[hashCode];

                getline(fileprogress,data);
                int pronunciationProgress = std::stoi(data);

                getline(fileprogress,data);
                int meaningProgress = std::stoi(data);

                w.setPronunciationProgress(pronunciationProgress);
                w.setMeaningProgress(meaningProgress);

                // Classify the word depending on the progress numbers
                if (pronunciationProgress == MAX_PROGRESS && meaningProgress == MAX_PROGRESS){
                    auto position = std::find(newWords[i].begin(),newWords[i].end(),hashCode);
                    if(position != newWords[i].end()){
                        newWords[i].erase(position);
                        masteredWords[i].push_back(hashCode);
                    }
                } else if (pronunciationProgress != NO_PROGRESS && meaningProgress != NO_PROGRESS){
                    auto position = std::find(newWords[i].begin(),newWords[i].end(),hashCode);
                    if(position != newWords[i].end()){
                        newWords[i].erase(position);
                        practicingWords[i].push_back(hashCode);
                    }
                }

                // Get the next line, which can be a word containing kanji or a "#"
                getline(fileprogress,data);
            }
        }

        fileprogress.close();

        // Shuffle the vectors to make them more unpredictable
        auto rng = std::default_random_engine {};
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(std::begin(newWords[i]), std::end(newWords[i]), rng);
        std::shuffle(std::begin(practicingWords[i]), std::end(practicingWords[i]), rng);
        std::shuffle(std::begin(masteredWords[i]), std::end(masteredWords[i]), rng);
    }
}

int WordRepository::getMasteredWords(int wordGrade){
    return masteredWords[wordGrade].size();
}

int WordRepository::getTotalWords(int wordGrade){
    return newWords[wordGrade].size() + practicingWords[wordGrade].size() + masteredWords[wordGrade].size();
}

Exercise WordRepository::getExercise(int grade, bool mastered)
{
    Exercise exercise;

    if(!mastered && newWords[grade].size() > 0 && util::shouldLearnNewContent(practicingWords[grade].size(), true)){

        int attemptsLeft = 5;
        while(attemptsLeft > 0){

            bool iterationFailed = false;

            // If we have to select a new word, the situation is more complex than it may seem
            // because we have to select a word such as its kanji componentes are known by the player
            hash_t hashCode = newWords[grade].back();
            Word& chosenWord = words[hashCode];

            for(wchar_t wchar : chosenWord.getWord()){
                Kanji k = KanjiRepository::getInstance()->getKanji(util::hash(std::wstring(1,wchar)));
                // If the kanji found is actually a kanji and not a hiragana, and if it's a
                // completely new kanji, then the word can't be taught (not yet, at least)
                if(k.getKanji() != L"" && k.isNew()){
                    // There is a kanji that the player doesn't know, failed attempts
                    iterationFailed = true;
                    break;
                }
            }

            // Try again
            if(iterationFailed) {
                attemptsLeft--;
                // Maybe this is very expensive but anyways
                newWords[grade].pop_back();
                newWords[grade].insert(newWords[grade].begin(),hashCode);
                continue;
            }

            // A good exercise could finally be found, exit the loop
            exercise = getTutorial(hashCode);

            chosenWord.setPronunciationProgress(0);
            chosenWord.setMeaningProgress(0);

            newWords[grade].pop_back();
            practicingWords[grade].push_back(hashCode);
            break;
        }

        if(attemptsLeft == 0)
            exercise.setExerciseType(ProgramState::TitleScreen);

    } else if(!mastered && practicingWords[grade].size() == 0){
        exercise.setExerciseType(ProgramState::TitleScreen);
    } else {

        // Choose the word
        hash_t hashCode = mastered
                                 ?
                                 masteredWords[grade][rand()%masteredWords[grade].size()]
                                 :
                                 practicingWords[grade][rand()%practicingWords[grade].size()];


        Word &chosenWord = words[hashCode];

        exercise.setHashCode(hashCode);

        // Choose the type of question
        int exerciseType = rand()%2;

        bool decided = false;

        while(!decided){
            switch(exerciseType){
            case 0:
                if(!mastered && chosenWord.getPronunciationProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%2;
                else decided = true;
                break;

            case 1:
                if(!mastered && chosenWord.getMeaningProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%2;
                else decided = true;
                break;
            }
        }


        // Set for the answers that the exercise will have
        std::set<std::wstring> exerciseAnswers;

        // Vector that contains words that will be used to get wrong answers. Get the
        // vector with the most words of this grade
        std::vector<hash_t> &wrongAnswerWords =
        newWords[grade].size() >= practicingWords[grade].size()
        &&
        newWords[grade].size() >= masteredWords[grade].size()
        ?
        newWords[grade]
        :
        practicingWords[grade].size() >= newWords[grade].size()
        &&
        practicingWords[grade].size() >= masteredWords[grade].size()
        ?
        practicingWords[grade]
        :
        masteredWords[grade];

        // Add the correct answers first and then the wrong answers
        switch(exerciseType){
        case 0:
        {
            exercise.setExerciseType(ProgramState::WordPron);
            exerciseAnswers.insert(chosenWord.getPronunciation());

            int index = rand()%wrongAnswerWords.size();

            while(exerciseAnswers.size() < 6) {
                std::wstring pronunciation = words[wrongAnswerWords[index]].getPronunciation();
                if(exerciseAnswers.count(pronunciation))
                    continue;
                exerciseAnswers.insert(pronunciation);
                index = (index+1)%wrongAnswerWords.size();
            }
        }
            break;
        case 1:
        {
            exercise.setExerciseType(ProgramState::WordMean);
            exerciseAnswers.insert(chosenWord.getMeaning());

            int index = rand()%wrongAnswerWords.size();

            while(exerciseAnswers.size() < 6) {
                std::wstring meaning = words[wrongAnswerWords[index]].getMeaning();
                if(exerciseAnswers.count(meaning))
                    continue;
                exerciseAnswers.insert(meaning);
                index = (index+1)%wrongAnswerWords.size();
            }
        }
            break;
        }

        exercise.setQuestion(chosenWord.getWord());

        exercise.setAnswers(exerciseAnswers);

        exercise.setPronunciationProgress(chosenWord.getPronunciationProgress());
        exercise.setMeaningProgress(chosenWord.getMeaningProgress());

        switch(exercise.getExerciseType()){
        case ProgramState::WordPron:
            exercise.setHelp(L"Choose the\ncorrect pronunciation\nfor the word\nshown");
            break;
        case ProgramState::WordMean:
            exercise.setHelp(L"Choose the\ncorrect meaning\nfor the word\nshown");
            break;
        default:
            break;
        }
    }

    return exercise;
}

Exercise WordRepository::getTutorial(hash_t hashCode){

    Exercise exercise;

    exercise.setExerciseType(ProgramState::WordTutor);

    // Choose the word
    Word &chosenWord = words[hashCode];

    exercise.setHelp(L"Memorize the\ninformation\nabout the\nnew word");

    exercise.setHashCode(hashCode);

    exercise.setTutorialMeaning(chosenWord.getMeaning());

    exercise.setWordPronunciation(chosenWord.getPronunciation());

    exercise.setQuestion(chosenWord.getWord());

    return exercise;
}

Exercise WordRepository::getMasteredExercise()
{
    int grade = 1 + rand() % 5;

    int counter = 0;

    while(counter<=5){
        counter++;
        if(masteredWords[grade].empty()){
            grade++;
            if (grade == 6) grade = 1;
        } else break;
    }

    if(counter <= 5) return getExercise(grade,true);
    else{
        Exercise e;
        e.setExerciseType(ProgramState::TitleScreen);
        return e;
    }
}

bool WordRepository::checkAnswer(Exercise &exercise, std::wstring answer)
{
    Word &word = words[exercise.getHashCode()];

    bool correct = false;

    switch(exercise.getExerciseType()){
    case ProgramState::WordPron:
        correct = word.getPronunciation() == answer;
        if(correct) {
            exercise.setPronunciationProgress(exercise.getPronunciationProgress() + CORRECT_PRON_POINTS);
            if(exercise.getPronunciationProgress() > MAX_PROGRESS) exercise.setPronunciationProgress(MAX_PROGRESS);
        } else {
            exercise.setPronunciationProgress(exercise.getPronunciationProgress() - INCORRECT_PRON_POINTS);
            if(exercise.getPronunciationProgress() < MIN_PROGRESS) exercise.setPronunciationProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::WordMean:
        correct = word.getMeaning() == answer;
        if(correct) {
            exercise.setMeaningProgress(exercise.getMeaningProgress() + CORRECT_WORDMEAN_POINTS);
            if(exercise.getMeaningProgress() > MAX_PROGRESS) exercise.setMeaningProgress(MAX_PROGRESS);
        } else {
            exercise.setMeaningProgress(exercise.getMeaningProgress() - INCORRECT_WORDMEAN_POINTS);
            if(exercise.getMeaningProgress() < MIN_PROGRESS) exercise.setMeaningProgress(MIN_PROGRESS);
        }
        break;
    default:
        return false;
    }

    word.setPronunciationProgress(exercise.getPronunciationProgress());
    word.setMeaningProgress(exercise.getMeaningProgress());

    if(word.getPronunciationProgress() == MAX_PROGRESS &&
        word.getMeaningProgress() == MAX_PROGRESS){
        auto position = std::find(practicingWords[word.getGrade()].begin(),practicingWords[word.getGrade()].end(),exercise.getHashCode());
        if(position != practicingWords[word.getGrade()].end()){
            practicingWords[word.getGrade()].erase(position);
            masteredWords[word.getGrade()].push_back(exercise.getHashCode());
        }
    } else {
        auto position = std::find(masteredWords[word.getGrade()].begin(),masteredWords[word.getGrade()].end(),exercise.getHashCode());
        if(position != masteredWords[word.getGrade()].end()){
            masteredWords[word.getGrade()].erase(position);
            practicingWords[word.getGrade()].push_back(exercise.getHashCode());
        }
    }

    return correct;
}

bool WordRepository::allAnswered(Exercise &exercise, unsigned int answers)
{
    bool completed = false;

    switch(exercise.getExerciseType()){
    case ProgramState::WordPron:
        completed = answers == 1;
        break;
    case ProgramState::WordMean:
        completed = answers == 1;
        break;
    default:
        return false;
    }

    return completed;
}

void WordRepository::save(){

    std::map<int,std::wfstream> files;

    for(int i=1;i<=5;i++)
        files[i] = std::wfstream("save/JLPTN"+std::to_string(i)+"wordprogress.txt",std::wfstream::trunc | std::wfstream::out);

    for(auto &pair : words){
        files[pair.second.getGrade()] << util::hash(pair.second.getWord()) << L"\n" << pair.second.getPronunciationProgress() << L"\n" << pair.second.getMeaningProgress() << L"\n";
    }

    for(auto &pair : files){
        pair.second << L"#";
        pair.second.close();
    }
}
