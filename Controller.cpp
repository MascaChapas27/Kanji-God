#include "Controller.hpp"
#include "KanjiRepository.hpp"
#include "Utilities.hpp"
#include "SFML/System.hpp"

Controller * Controller::controller = nullptr;

Controller * Controller::getInstance(){
    if(controller == nullptr) controller = new Controller();
    return controller;
}

void Controller::setGradeAndMode(int selectedGrade, bool kanjiMode){
    this->selectedGrade = selectedGrade;
    this->kanjiMode = kanjiMode;
}

void Controller::setGodMode(bool godMode){
    this->godMode = godMode;
}

// Returns exercise
Exercise Controller::getExercise(){

    correctAnswers.clear();

    Exercise exercise;

    if(kanjiMode){
        exercise = KanjiRepository::getInstance()->getExercise(selectedGrade);
    }

    currentExercise = exercise;
    return exercise;
}

bool Controller::checkAnswer(std::wstring answer, int &meanProgress, int &kunProgress, int &onProgress){

    // That answer was already answered
    if(correctAnswers.count(answer)) return true;

    bool correct = false;

    switch(currentExercise.getExerciseType()){
    case ProgramState::KanjiKun:
    case ProgramState::KanjiOn:
    case ProgramState::KanjiMean:
        correct = KanjiRepository::getInstance()->checkAnswer(currentExercise, answer);
        meanProgress = currentExercise.getMeaningProgress();
        kunProgress = currentExercise.getKunyomiProgress();
        onProgress = currentExercise.getOnyomiProgress();
        break;
    
    case ProgramState::WordMean:
    case ProgramState::WordPron:
        // correct = WordRepository::...
        break;
    default:
        break;
    }
    
    // bool correct = answer == L"おと" || answer == L"ね";
    if(correct) correctAnswers.insert(answer);
    return correct;
}

bool Controller::allAnswered(){
    
    switch(currentExercise.getExerciseType()){
    case ProgramState::KanjiKun:
    case ProgramState::KanjiOn:
    case ProgramState::KanjiMean:
        
        return KanjiRepository::getInstance()->allAnswered(currentExercise, correctAnswers.size());
        break;
    
    case ProgramState::WordMean:
    case ProgramState::WordPron:
        return false;
        break;
    default:
        return false;
        break;
    }
}
