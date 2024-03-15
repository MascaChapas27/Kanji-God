#include "Controller.hpp"

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

    Exercise exercise;

    exercise.setExerciseType(ProgramState::KanjiKun);
    exercise.setQuestion(rand()%2 ? L"音楽" : L"寿");

    return exercise;
}
