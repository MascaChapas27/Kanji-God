#include "Controller.hpp"
#include "KanjiRepository.hpp"
#include "SFML/System.hpp"
#include <iostream>

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

    return exercise;
}

bool Controller::checkAnswer(std::wstring answer){
    bool correct = answer == L"おと" || answer == L"ね";
    if(correct && !correctAnswers.count(answer))
        correctAnswers.insert(answer);
    return correct;
}

bool Controller::allAnswered(){
    return correctAnswers.size() == 2;
}
