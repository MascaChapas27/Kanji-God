#include "KanjiRepository.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"
#include "FuckWindows.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>

KanjiRepository * KanjiRepository::kanjiRepository = nullptr;

KanjiRepository * KanjiRepository::getInstance()
{
    if(kanjiRepository == nullptr) {
        kanjiRepository = new KanjiRepository;
        kanjiRepository->loadAllKanjis();
    }
    return kanjiRepository;
}

// Operation that loads all kanji and progress for kanji in one file
void KanjiRepository::loadAllKanjis(){

    for(int i=2;i<=5;i++){

        // Open the readings/meanings file
        #ifdef __linux__
        std::wfstream file("files/JLPTN" + std::to_string(i) + "kanji.txt");

        if(!file.is_open()){
            std::cerr << "ERROR: file " << "files/JLPTN" << std::to_string(i) << "kanji.txt" <<" not found" << std::endl;
            exit(EXIT_FAILURE);
        }

        file.imbue(std::locale("C.UTF-8"));
        #else
        std::wstringstream file(FuckWindows::aaa[i]);
        #endif
        std::wstring data;

        // Line that should be a kanji symbol (or "#")
        getline(file,data);

        while(data != L"#"){
            Kanji k;

            k.setGrade(i);

            k.setKanji(data);

            // Read the meaning
            getline(file,data);

            k.setMeaning(data);

            std::set<std::wstring> onyomi;
            // Read the onyomi readings
            getline(file,data);

            while( data != L""){
                onyomi.insert(data);
                getline(file,data);
            }

            k.setOnyomiReadings(onyomi);

            std::set<std::wstring> kunyomi;
            // Read the onyomi readings
            getline(file,data);
            while(data != L"ーーーー"){
                kunyomi.insert(data);
                getline(file,data);
            }

            k.setKunyomiReadings(kunyomi);

            k.setKunyomiProgress(-1);
            k.setOnyomiProgress(-1);
            k.setMeaningProgress(-1);

            hash_t hash = util::hash(k.getKanji());

            newKanjis[i].push_back(hash);

            kanjis[hash] = k;

            // Kanji symbol or "#"
            getline(file,data);
        }

        #ifdef __linux__
        file.close();
        #endif

        // Open the progress file
        std::wfstream fileprogress("files/JLPTN" + std::to_string(i) + "kanjiprogress.txt");

        if(!fileprogress.is_open()){
            // The file doesn't exist: let's create it
            fileprogress.open("files/JLPTN" + std::to_string(i) + "kanjiprogress.txt",std::fstream::out);

            for(hash_t hashCode : newKanjis[i]){
                fileprogress << hashCode << "\n-1\n-1\n-1\n";
                kanjis[hashCode].setMeaningProgress(-1);
                kanjis[hashCode].setKunyomiProgress(-1);
                kanjis[hashCode].setOnyomiProgress(-1);
            }

            fileprogress << "#";
        } else {

            // First line, can be a "#" or a hash code
            getline(fileprogress,data);

            while(data != L"#"){

                hash_t hashCode = std::stoul(data);

                // Get the kanji and assign it the progress numbers
                Kanji &k = kanjis[hashCode];

                getline(fileprogress,data);
                int meaningProgress = std::stoi(data);

                getline(fileprogress,data);
                int kunyomiProgress = std::stoi(data);

                getline(fileprogress,data);
                int onyomiProgress = std::stoi(data);

                k.setMeaningProgress(meaningProgress);
                k.setKunyomiProgress(kunyomiProgress);
                k.setOnyomiProgress(onyomiProgress);

                // Classify the kanji depending on the progress numbers
                if (meaningProgress == MAX_PROGRESS && kunyomiProgress == MAX_PROGRESS && onyomiProgress == MAX_PROGRESS){
                    auto position = std::find(newKanjis[i].begin(),newKanjis[i].end(),hashCode);
                    if(position != newKanjis[i].end()){
                        newKanjis[i].erase(position);
                        masteredKanjis[i].push_back(hashCode);
                    }
                } else if (meaningProgress != NO_PROGRESS && kunyomiProgress != NO_PROGRESS && onyomiProgress != NO_PROGRESS){
                    auto position = std::find(newKanjis[i].begin(),newKanjis[i].end(),hashCode);
                    if(position != newKanjis[i].end()){
                        newKanjis[i].erase(position);
                        practicingKanjis[i].push_back(hashCode);
                    }
                }

                // Get the next line, which can be a hash code or a "#"
                getline(fileprogress,data);
            }
        }

        fileprogress.close();

        // Shuffle the vectors to make them more unpredictable
        auto rng = std::default_random_engine {};
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(std::begin(newKanjis[i]), std::end(newKanjis[i]), rng);
        std::shuffle(std::begin(practicingKanjis[i]), std::end(practicingKanjis[i]), rng);
        std::shuffle(std::begin(masteredKanjis[i]), std::end(masteredKanjis[i]), rng);
    }
}

Kanji KanjiRepository::getKanji(hash_t hashCode)
{
    if(kanjis.count(hashCode))
        return kanjis[hashCode];
    
    // If the kanji can't be found, return an empty kanji
    Kanji k;
    k.setKanji(L"");
    return k;
}

int KanjiRepository::getMasteredKanji(int kanjiGrade){
    return masteredKanjis[kanjiGrade].size();
}

int KanjiRepository::getTotalKanji(int kanjiGrade){
    return newKanjis[kanjiGrade].size() + practicingKanjis[kanjiGrade].size() + masteredKanjis[kanjiGrade].size();
}

Exercise KanjiRepository::getExercise(int grade, bool mastered)
{
    Exercise exercise;

    if(!mastered && newKanjis[grade].size() > 0 && util::shouldLearnNewContent(practicingKanjis[grade].size(),false)){

        hash_t hashCode = newKanjis[grade].back();
        Kanji& chosenKanji = kanjis[hashCode];

        exercise = getTutorial(hashCode);

        chosenKanji.setKunyomiProgress(chosenKanji.getKunyomiReadings().empty() ? 100 : 0);
        chosenKanji.setOnyomiProgress(chosenKanji.getOnyomiReadings().empty() ? 100 : 0);
        chosenKanji.setMeaningProgress(0);

        newKanjis[grade].pop_back();
        practicingKanjis[grade].push_back(hashCode);

    } else if(!mastered && practicingKanjis[grade].size() == 0){
        exercise.setExerciseType(ProgramState::TitleScreen);
    } else {

        // Choose the kanji
        Kanji &chosenKanji = kanjis[mastered
                                    ?
                                    masteredKanjis[grade][rand()%masteredKanjis[grade].size()]
                                    :
                                    practicingKanjis[grade][rand()%practicingKanjis[grade].size()]];

        exercise.setHashCode(util::hash(chosenKanji.getKanji()));

        // Choose the type of question
        int exerciseType = rand()%3;

        bool decided = false;

        while(!decided){
            switch(exerciseType){
            case 0:
                if(!mastered && chosenKanji.getMeaningProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;

            case 1:
                if((!mastered && chosenKanji.getKunyomiProgress()==MAX_PROGRESS) ||
                   (mastered && chosenKanji.getKunyomiReadings().size() == 0))
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;

            case 2:
                if((!mastered && chosenKanji.getOnyomiProgress()==MAX_PROGRESS) ||
                   (mastered && chosenKanji.getOnyomiReadings().size() == 0))
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;
            }
        }


        // Set for the answers that the exercise will have
        std::set<std::wstring> exerciseAnswers;

        // Vector that contains kanjis that will be used to get wrong answers. Get the
        // vector with the most kanjis of this grade
        std::vector<hash_t> &wrongAnswerKanjis =
        newKanjis[grade].size() >= practicingKanjis[grade].size()
        &&
        newKanjis[grade].size() >= masteredKanjis[grade].size()
        ?
        newKanjis[grade]
        :
        practicingKanjis[grade].size() >= newKanjis[grade].size()
        &&
        practicingKanjis[grade].size() >= masteredKanjis[grade].size()
        ?
        practicingKanjis[grade]
        :
        masteredKanjis[grade];

        // Add the correct answers first and then the wrong answers
        switch(exerciseType){
        case 0:
        {
            exercise.setExerciseType(ProgramState::KanjiMean);
            exerciseAnswers.insert(chosenKanji.getMeaning());

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 6) {
                std::wstring meaning = kanjis[wrongAnswerKanjis[index]].getMeaning();
                if(exerciseAnswers.count(meaning))
                    continue;
                exerciseAnswers.insert(meaning);
                index = (index+1)%wrongAnswerKanjis.size();
            }
        }
            break;
        case 1:
        {
            exercise.setExerciseType(ProgramState::KanjiKun);
            for(std::wstring answer : chosenKanji.getKunyomiReadings())
                exerciseAnswers.insert(answer);

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 9) {
                for(std::wstring kunyomi : kanjis[wrongAnswerKanjis[index]].getKunyomiReadings()){
                    if(exerciseAnswers.count(kunyomi))
                        continue;
                    if(exerciseAnswers.size() == 9)
                        break;
                    exerciseAnswers.insert(kunyomi);
                }
                index = (index+1)%wrongAnswerKanjis.size();
            }
        }
            break;
        case 2:
        {
            exercise.setExerciseType(ProgramState::KanjiOn);
            for(std::wstring answer : chosenKanji.getOnyomiReadings())
                exerciseAnswers.insert(answer);

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 9) {
                for(std::wstring onyomi : kanjis[wrongAnswerKanjis[index]].getOnyomiReadings()){
                    if(exerciseAnswers.count(onyomi))
                        continue;
                    if(exerciseAnswers.size() == 9)
                        break;
                    exerciseAnswers.insert(onyomi);
                }
                index = (index+1)%wrongAnswerKanjis.size();
            }
            break;
        }
        }

        exercise.setQuestion(chosenKanji.getKanji());

        exercise.setAnswers(exerciseAnswers);

        exercise.setKunyomiProgress(chosenKanji.getKunyomiProgress());
        exercise.setOnyomiProgress(chosenKanji.getOnyomiProgress());
        exercise.setMeaningProgress(chosenKanji.getMeaningProgress());

        switch(exercise.getExerciseType()){
        case ProgramState::KanjiKun:
            exercise.setHelp(L"Choose the\ncorrect kunyomi\nreadings for\nthe kanji shown");
            break;
        case ProgramState::KanjiOn:
            exercise.setHelp(L"Choose the\ncorrect onyomi\nreadings for\nthe kanji shown");
            break;
        case ProgramState::KanjiMean:
            exercise.setHelp(L"Choose the\ncorrect meaning\nfor the\nkanji shown");
            break;
        default:
            break;
        }
    }

    return exercise;
}

Exercise KanjiRepository::getMasteredExercise()
{
    int grade = 1 + rand() % 5;

    int counter = 0;

    while(counter<=5){
        counter++;
        if(masteredKanjis[grade].empty()){
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

Exercise KanjiRepository::getTutorial(hash_t hashCode)
{
    Exercise exercise;

    exercise.setExerciseType(ProgramState::KanjiTutor);

    Kanji &chosenKanji = kanjis[hashCode];

    exercise.setHelp(L"Memorize the\ninformation\nabout the\nnew kanji");

    exercise.setHashCode(hashCode);

    exercise.setTutorialMeaning(chosenKanji.getMeaning());

    exercise.setKunyomiPronunciations(chosenKanji.getKunyomiReadings());

    exercise.setOnyomiPronunciations(chosenKanji.getOnyomiReadings());

    exercise.setQuestion(chosenKanji.getKanji());

    return exercise;
}

bool KanjiRepository::checkAnswer(Exercise &exercise, std::wstring answer)
{
    Kanji &kanji = kanjis[exercise.getHashCode()];

    bool correct = false;

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        correct = kanji.getKunyomiReadings().count(answer);
        if(correct) {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() + CORRECT_KUN_POINTS/kanji.getKunyomiReadings().size());
            if(exercise.getKunyomiProgress() > MAX_PROGRESS) exercise.setKunyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() - INCORRECT_KUN_POINTS);
            if(exercise.getKunyomiProgress() < MIN_PROGRESS) exercise.setKunyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiOn:
        correct = kanji.getOnyomiReadings().count(answer);
        if(correct) {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() + CORRECT_ON_POINTS/kanji.getOnyomiReadings().size());
            if(exercise.getOnyomiProgress() > MAX_PROGRESS) exercise.setOnyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() - INCORRECT_ON_POINTS);
            if(exercise.getOnyomiProgress() < MIN_PROGRESS) exercise.setOnyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiMean:
        correct = kanji.getMeaning() == answer;
        if(correct) {
            exercise.setMeaningProgress(exercise.getMeaningProgress() + CORRECT_KANJIMEAN_POINTS);
            if(exercise.getMeaningProgress() > MAX_PROGRESS) exercise.setMeaningProgress(MAX_PROGRESS);
        } else {
            exercise.setMeaningProgress(exercise.getMeaningProgress() - INCORRECT_KANJIMEAN_POINTS);
            if(exercise.getMeaningProgress() < MIN_PROGRESS) exercise.setMeaningProgress(MIN_PROGRESS);
        }
        break;
    default:
        return false;
    }

    kanji.setMeaningProgress(exercise.getMeaningProgress());
    kanji.setKunyomiProgress(exercise.getKunyomiProgress());
    kanji.setOnyomiProgress(exercise.getOnyomiProgress());

    if(kanji.getMeaningProgress() == MAX_PROGRESS &&
        kanji.getKunyomiProgress() == MAX_PROGRESS &&
        kanji.getOnyomiProgress() == MAX_PROGRESS){
        auto position = std::find(practicingKanjis[kanji.getGrade()].begin(),practicingKanjis[kanji.getGrade()].end(),exercise.getHashCode());
        if(position != practicingKanjis[kanji.getGrade()].end()){
            practicingKanjis[kanji.getGrade()].erase(position);
            masteredKanjis[kanji.getGrade()].push_back(exercise.getHashCode());
        }
    } else {
        auto position = std::find(masteredKanjis[kanji.getGrade()].begin(),masteredKanjis[kanji.getGrade()].end(),exercise.getHashCode());
        if(position != masteredKanjis[kanji.getGrade()].end()){
            masteredKanjis[kanji.getGrade()].erase(position);
            practicingKanjis[kanji.getGrade()].push_back(exercise.getHashCode());
        }
    }

    return correct;
}

bool KanjiRepository::allAnswered(Exercise &exercise, unsigned int answers)
{
    Kanji &kanji = kanjis[exercise.getHashCode()];

    bool completed = false;

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        completed = kanji.getKunyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiOn:
        completed = kanji.getOnyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiMean:
        completed = answers == 1;
        break;
    default:
        return false;
    }

    return completed;
}

void KanjiRepository::save(){

    std::map<int,std::wfstream> files;

    for(int i=3;i<=5;i++){
        files[i] = std::wfstream("files/JLPTN"+std::to_string(i)+"kanjiprogress.txt",std::wfstream::trunc | std::wfstream::out);
    }

    for(auto &pair : kanjis){
        files[pair.second.getGrade()] << util::hash(pair.second.getKanji()) << L"\n" << pair.second.getMeaningProgress() << L"\n" << pair.second.getKunyomiProgress() << L"\n" << pair.second.getOnyomiProgress() << L"\n";
    }

    for(auto &pair : files){
        pair.second << L"#";
        pair.second.close();
    }
}
