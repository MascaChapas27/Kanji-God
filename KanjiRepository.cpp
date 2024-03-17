#include "KanjiRepository.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"

KanjiRepository * KanjiRepository::kanjiRepository = nullptr;

KanjiRepository * KanjiRepository::getInstance()
{
    if(kanjiRepository == nullptr) kanjiRepository = new KanjiRepository;
    return kanjiRepository;
}

// Operation that loads all kanji and progress for kanji in one file
void loadAllKanjis(){
    // For each grade

        // Open the file
        
        // Read kanjis individually

        // For each kanji read

            // Create the corresponding Kanji object and put it in the map
            
            // Check the progress and put its wstring in the corresponding vector
        
        // Close the file
}

// Updates the progress for a kanji
void updateKanji(std::wstring kanji, int meaning, int kunyomi, int onyomi){
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

    if(util::shouldLearnNewKanji(newKanjis[grade].size())){

        exercise.setExerciseType(ProgramState::KanjiTutor);

    } else {

        Kanji &chosenKanji = practicingKanjis[grade][rand()%practicingKanjis[grade].size()];

        int exerciseType = rand()%3;

        bool decided = false;

        while(!decided){
            switch(exerciseType){
                
            }
        }
        
        

        bool kun = chosenKanji.getKunyomiReadings().empty() || chosenKa

        exercise.setExerciseType(ProgramState::KanjiKun);

        exercise.setQuestion();

        std::vector<std::wstring> answers;

        for(std::wstring answer : kanjis[exercise.getQuestion()].)

        answers.push_back(L"あ");
        answers.push_back(L"おのおの");
        answers.push_back(L"しらべ");
        answers.push_back(L"くすり");
        answers.push_back(L"おとおと");
        answers.push_back(L"みずうみ");
        answers.push_back(L"つる");
        answers.push_back(L"おと");
        answers.push_back(L"ね");

        exercise.setAnswers(answers);

        exercise.setKunyomiProgress(10);
        exercise.setOnyomiProgress(30);
        exercise.setMeaningProgress(50);

        exercise.setHelp(L"Choose the\ncorrect kunyomi\nreadings for\nthe kanji shown");
    }

    return exercise;
}
