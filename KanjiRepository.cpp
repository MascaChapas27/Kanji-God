#include "KanjiRepository.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"
#include <fstream>

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
        std::wfstream file("files/grade" + std::to_string(i) + "kanji.txt");

        if(!file.is_open()){
            exit(EXIT_FAILURE);
        }

        file.imbue(std::locale("C.UTF-8"));

        std::wstring data;

        // Line that should be a kanji symbol (or "#")
        getline(file,data);

        while(data != L"#"){
            Kanji k;

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

            kanjis[k.getKanji()] = k;
            
            // Kanji symbol or "#"
            getline(file,data);

            classifiedKanjis.push_back(k.getKanji());
        }

        file.close();

        // Open the progress file
        file.open("files/grade" + std::to_string(i) + "kanjiprogress.txt");

        if(!file.is_open()){
            // The file doesn't exist: let's create it
            file.open("files/grade" + std::to_string(i) + "kanjiprogress.txt",std::wfstream::out);

            file.imbue(std::locale("C.UTF-8"));

            for(std::wstring kanjiName : classifiedKanjis){
                file << kanjiName << L"\n-1\n-1\n-1\n";
            }

            file << L"#";

            newKanjis[i] = classifiedKanjis;
        } else {
            file.imbue(std::locale("C.UTF-8"));

            // First line, can be a "#" or a kanji name
            getline(file,data);

            while(data != L"#"){
                
                // Get the kanji and assign it the progress numbers
                Kanji &k = kanjis[data];

                getline(file,data);
                int meaningProgress = std::stoi(data);

                getline(file,data);
                int kunyomiProgress = std::stoi(data);

                getline(file,data);
                int onyomiProgress = std::stoi(data);

                k.setMeaningProgress(meaningProgress);
                k.setKunyomiProgress(kunyomiProgress);
                k.setOnyomiProgress(onyomiProgress);

                // Classify the kanji depending on the progress numbers
                if(meaningProgress == NO_PROGRESS && kunyomiProgress == NO_PROGRESS && onyomiProgress == NO_PROGRESS){
                    practicingKanjis[i].push_back(k.getKanji());
                } else if (meaningProgress == MAX_PROGRESS && kunyomiProgress == MAX_PROGRESS && onyomiProgress == MAX_PROGRESS){
                    masteredKanjis[i].push_back(k.getKanji());
                } else {
                    practicingKanjis[i].push_back(k.getKanji());
                }

                // Get the next line, which can be a kanji name or a "#"
                getline(file,data);
            }
        }

        file.close();
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

Exercise KanjiRepository::getExercise(int grade)
{
    Exercise exercise;
/*
    if(util::shouldLearnNewKanji(newKanjis[grade].size())){

        exercise.setExerciseType(ProgramState::KanjiTutor);

    } else {*/

        // Choose the kanji
        Kanji &chosenKanji = kanjis[practicingKanjis[grade][rand()%practicingKanjis[grade].size()]];

        // Choose the type of question
        //int exerciseType = rand()%3;
        int exerciseType = 1;

        bool decided = false;

        while(!decided){
            switch(exerciseType){
            case 0:
                if(chosenKanji.getMeaningProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;

            case 1:
                if(chosenKanji.getKunyomiProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%3;
                else decided = true;
                break;
            
            case 2:
                if(chosenKanji.getOnyomiProgress()==MAX_PROGRESS)
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
            exercise.setExerciseType(ProgramState::KanjiMean);
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
            exercise.setExerciseType(ProgramState::KanjiOn);
            break;
        }
        
        exercise.setQuestion(chosenKanji.getKanji());

        /*
        answers.push_back(L"あ");
        answers.push_back(L"おのおの");
        answers.push_back(L"しらべ");
        answers.push_back(L"くすり");
        answers.push_back(L"おとおと");
        answers.push_back(L"みずうみ");
        answers.push_back(L"つる");
        answers.push_back(L"おと");
        answers.push_back(L"ね");
        */

        exercise.setAnswers(exerciseAnswers);

        exercise.setKunyomiProgress(chosenKanji.getKunyomiProgress());
        exercise.setOnyomiProgress(chosenKanji.getOnyomiProgress());
        exercise.setMeaningProgress(chosenKanji.getMeaningProgress());

        switch(exercise.getExerciseType()){
        case ProgramState::KanjiKun:
            exercise.setHelp(L"Choose the\ncorrect kunyomi\nreadings for\nthe kanji shown");
            break;
        }
    //}

    return exercise;
}

bool KanjiRepository::checkAnswer(Exercise exercise, std::wstring answer)
{
    Kanji &kanji = kanjis[exercise.getQuestion()];

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        return kanji.getKunyomiReadings().count(answer);
        break;
    case ProgramState::KanjiOn:
        return kanji.getOnyomiReadings().count(answer);
        break;
    case ProgramState::KanjiMean:
        return kanji.getMeaning() == answer;
        break;
    default:
        return false;
    }
}

bool KanjiRepository::allAnswered(Exercise exercise, int answers)
{
    Kanji &kanji = kanjis[exercise.getQuestion()];

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        return kanji.getKunyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiOn:
        return kanji.getOnyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiMean:
        return true;
        break;
    default:
        return false;
    }
}