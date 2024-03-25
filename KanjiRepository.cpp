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
    if(kanjiRepository == nullptr) kanjiRepository = new KanjiRepository;
    return kanjiRepository;
}

// Operation that loads all kanji and progress for kanji in one file
void KanjiRepository::loadAllKanjis(){

    for(int i=1;i<2;i++){

        std::vector<std::wstring> classifiedKanjis;

        // Open the readings/meanings file
        #ifdef __linux__
        std::wfstream file("files/grade" + std::to_string(i) + "kanji.txt");

        if(!file.is_open()){
            std::cerr << "ERROR: file " << "files/grade" << std::to_string(i) << "kanji.txt" <<" not found" << std::endl;
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

            kanjis[k.getMeaning()] = k;

            // Kanji symbol or "#"
            getline(file,data);

            classifiedKanjis.push_back(k.getMeaning());
        }

        #ifdef __linux__
        file.close();
        #endif

        // Open the progress file
        std::wfstream fileprogress("files/grade" + std::to_string(i) + "kanjiprogress.txt");

        if(!fileprogress.is_open()){
            // The file doesn't exist: let's create it
            fileprogress.open("files/grade" + std::to_string(i) + "kanjiprogress.txt",std::fstream::out);

            for(std::wstring kanjiMeaning : classifiedKanjis){
                fileprogress << kanjiMeaning << "\n-1\n-1\n-1\n";
                kanjis[kanjiMeaning].setMeaningProgress(-1);
                kanjis[kanjiMeaning].setKunyomiProgress(-1);
                kanjis[kanjiMeaning].setOnyomiProgress(-1);
            }

            fileprogress << "#";

            newKanjis[i] = classifiedKanjis;
        } else {

            // First line, can be a "#" or a kanji name
            getline(fileprogress,data);

            while(data != L"#"){

                // Get the kanji and assign it the progress numbers
                Kanji &k = kanjis[data];

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
                if(meaningProgress == NO_PROGRESS && kunyomiProgress == NO_PROGRESS && onyomiProgress == NO_PROGRESS){
                    newKanjis[i].push_back(k.getMeaning());
                } else if (meaningProgress == MAX_PROGRESS && kunyomiProgress == MAX_PROGRESS && onyomiProgress == MAX_PROGRESS){
                    masteredKanjis[i].push_back(k.getMeaning());
                } else {
                    practicingKanjis[i].push_back(k.getMeaning());
                }

                // Get the next line, which can be a kanji name or a "#"
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

        // For each kanji read

            // Create the corresponding Kanji object and put it in the map

            // Check the progress and put its wstring in the corresponding vector

        // Close the file
}

// Updates the progress for a kanji
void KanjiRepository::updateKanji(std::wstring kanji, int meaning, int kunyomi, int onyomi){
    // Check if the kanji was new and if it is no more
    // move it from one vector to another

    // Check if the kanji was practicing and if it is now mastered move
    // it from one vector to another

    // Check if the kanji was mastered and if it is no more move it
    // from one vector to another

    // Finally change the kanji data in the map
}

Exercise KanjiRepository::getExercise(int grade, bool mastered)
{
    Exercise exercise;

    if(!mastered && newKanjis[grade].size() > 0 && util::shouldLearnNewKanji(practicingKanjis[grade].size())){

        exercise.setExerciseType(ProgramState::KanjiTutor);

        // Choose the kanji
        Kanji &chosenKanji = kanjis[newKanjis[grade].back()];

        exercise.setHelp(L"Memorize the\ninformation\nabout the\nnew kanji");

        exercise.setId(chosenKanji.getMeaning());

        exercise.setKunyomiPronunciations(chosenKanji.getKunyomiReadings());

        exercise.setOnyomiPronunciations(chosenKanji.getOnyomiReadings());

        exercise.setQuestion(chosenKanji.getKanji());

        chosenKanji.setKunyomiProgress(chosenKanji.getKunyomiReadings().empty() ? 100 : 0);
        chosenKanji.setOnyomiProgress(chosenKanji.getOnyomiReadings().empty() ? 100 : 0);
        chosenKanji.setMeaningProgress(0);

        newKanjis[grade].pop_back();
        practicingKanjis[grade].push_back(chosenKanji.getMeaning());

    } else {

        // Choose the kanji
        Kanji &chosenKanji = kanjis[mastered
                                    ?
                                    masteredKanjis[grade][rand()%masteredKanjis[grade].size()]
                                    :
                                    practicingKanjis[grade][rand()%practicingKanjis[grade].size()]];

        exercise.setId(chosenKanji.getMeaning());

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
                if(!mastered && chosenKanji.getKunyomiProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;

            case 2:
                if(!mastered && chosenKanji.getOnyomiProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;
            }
        }
        

        // Set for the answers that the exercise will have
        std::set<std::wstring> exerciseAnswers;

        // Vector that contains kanjis that will be used to get wrong answers. Get the
        // vector with the most kanjis of this grade
        std::vector<std::wstring> &wrongAnswerKanjis =
        newKanjis[grade].size() > practicingKanjis[grade].size()
        &&
        newKanjis[grade].size() > masteredKanjis[grade].size()
        ?
        newKanjis[grade]
        :
        practicingKanjis[grade].size() > newKanjis[grade].size()
        &&
        practicingKanjis[grade].size() > masteredKanjis[grade].size()
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

            while(exerciseAnswers.size() < 9) {
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
        exercise.setId(chosenKanji.getMeaning());

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
        }
    }

    return exercise;
}

Exercise KanjiRepository::getMasteredExercise()
{
    // int grade = 1 + rand() % 6;
    int grade = 1;

    int counter = 0;

    while(counter<6){
        counter++;
        if(masteredKanjis[grade].empty()){
            grade++;
            if (grade == 6) grade = 1;
        } else break;
    }

    if(counter < 6) return getExercise(grade,true);
    else{
        Exercise e;
        e.setExerciseType(ProgramState::TitleScreen);
        return e;
    }
}

bool KanjiRepository::checkAnswer(Exercise &exercise, std::wstring answer)
{
    Kanji &kanji = kanjis[exercise.getId()];

    bool correct = false;

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        correct = kanji.getKunyomiReadings().count(answer);
        if(correct) {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() + 1);
            if(exercise.getKunyomiProgress() > MAX_PROGRESS) exercise.setKunyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() - 2);
            if(exercise.getKunyomiProgress() < MIN_PROGRESS) exercise.setKunyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiOn:
        correct = kanji.getOnyomiReadings().count(answer);
        if(correct) {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() + 1);
            if(exercise.getOnyomiProgress() > MAX_PROGRESS) exercise.setOnyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() - 2);
            if(exercise.getOnyomiProgress() < MIN_PROGRESS) exercise.setOnyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiMean:
        correct = kanji.getMeaning() == answer;
        if(correct) {
            exercise.setMeaningProgress(exercise.getMeaningProgress() + 3);
            if(exercise.getMeaningProgress() > MAX_PROGRESS) exercise.setMeaningProgress(MAX_PROGRESS);
        } else {
            exercise.setMeaningProgress(exercise.getMeaningProgress() - 5);
            if(exercise.getMeaningProgress() < MIN_PROGRESS) exercise.setMeaningProgress(MIN_PROGRESS);
        }
        break;
    default:
        return false;
    }

    return correct;
}

bool KanjiRepository::allAnswered(Exercise &exercise, int answers)
{
    Kanji &kanji = kanjis[exercise.getId()];

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

    if(completed){
        kanji.setMeaningProgress(exercise.getMeaningProgress());
        kanji.setKunyomiProgress(exercise.getKunyomiProgress());
        kanji.setOnyomiProgress(exercise.getOnyomiProgress());

        if(kanji.getMeaningProgress() == MAX_PROGRESS && 
           kanji.getKunyomiProgress() == MAX_PROGRESS &&
           kanji.getOnyomiProgress() == MAX_PROGRESS){
            auto position = std::find(practicingKanjis[kanji.getGrade()].begin(),practicingKanjis[kanji.getGrade()].end(),kanji.getMeaning());
            if(position != practicingKanjis[kanji.getGrade()].end()){
                practicingKanjis[kanji.getGrade()].erase(position);
                masteredKanjis[kanji.getGrade()].push_back(kanji.getMeaning());
            }
        } else {
            auto position = std::find(masteredKanjis[kanji.getGrade()].begin(),masteredKanjis[kanji.getGrade()].end(),kanji.getMeaning());
            if(position != masteredKanjis[kanji.getGrade()].end()){
                masteredKanjis[kanji.getGrade()].erase(position);
                practicingKanjis[kanji.getGrade()].push_back(kanji.getMeaning());
            }
        }
    }

    return completed;
}

void KanjiRepository::save(){

    std::map<int,std::wfstream> files;

    files[1] = std::wfstream("files/grade1kanjiprogress.txt",std::wfstream::trunc | std::wfstream::out);

    for(auto &pair : kanjis){
        switch(pair.second.getGrade()){
        case 1:
            files[1] << pair.second.getMeaning() << L"\n" << pair.second.getMeaningProgress() << L"\n" << pair.second.getKunyomiProgress() << L"\n" << pair.second.getOnyomiProgress() << L"\n";
            break;
        }
    }

    for(auto &pair : files){
        pair.second << L"#";
        pair.second.close();
    }
}