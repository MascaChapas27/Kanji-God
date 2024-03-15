#include "Controller.hpp"
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

    Exercise exercise;

    if(kanjiMode){
        exercise.setExerciseType(ProgramState::KanjiKun);
        exercise.setQuestion(L"音楽");

        std::list<std::wstring> answers;

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

        exercise.setHelp(L"Choose the correct\nkunyomi readings for\nthe kanji shown");
    }

    return exercise;
}

bool Controller::checkAnswer(std::wstring answer){
    return answer == L"おと" || answer == L"ね";
}