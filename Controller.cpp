#include "Controller.hpp"

static Controller * Controller::getInstance(){
    if(this->controller == nullptr) controller = new Controller;
    return controller;
}

void Controller::setGradeAndMode(int selectedGrade, bool kanjiMode){
    this->selectedGrade = selectedGrade;
    this->kanjiMode = kanjiMode;
}

void Controller::setGodMode(bool godMode){
    this->godMode == godMode;
}

// Returns exercise
Exercise Controller::getExercise(){

    Exercise exercise;

    // stuff

    return exercise;
}