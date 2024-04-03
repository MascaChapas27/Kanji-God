#include "Controller.hpp"
#include "KanjiRepository.hpp"
#include "WordRepository.hpp"
#include "Utilities.hpp"
#include "SFML/System.hpp"

Controller * Controller::controller = nullptr;

sf::Sound Controller::correctAnswerSound = util::initializeSound(SoundID::CorrectAnswer);
sf::Sound Controller::incorrectAnswerSound = util::initializeSound(SoundID::IncorrectAnswer);

Controller * Controller::getInstance(){
    if(controller == nullptr) controller = new Controller();
    return controller;
}

void Controller::setGradeAndMode(int selectedGrade, bool kanjiMode){
    this->selectedGrade = selectedGrade;
    this->kanjiMode = kanjiMode;
    this->godMode = false;
}

void Controller::setGodMode(bool godMode){
    this->godMode = godMode;
}

// Returns exercise
Exercise Controller::getExercise(){

    correctAnswers.clear();

    Exercise exercise;

    if(godMode){
        int whatType = rand()%2;
        int numAttempts = 0;
        do {
            numAttempts++;
            whatType = (whatType+1) % 2;
            switch (whatType)
            {
            case 0:
                exercise = KanjiRepository::getInstance()->getMasteredExercise();
                break;
            case 1:
                exercise = WordRepository::getInstance()->getMasteredExercise();
                break;
            }
        } while(numAttempts < 2 && exercise.getExerciseType() == ProgramState::TitleScreen);

    } else if(kanjiMode){
        exercise = KanjiRepository::getInstance()->getExercise(selectedGrade);
    } else{
        exercise = WordRepository::getInstance()->getExercise(selectedGrade);
    }

    currentExercise = exercise;
    return exercise;
}

bool Controller::checkAnswer(std::wstring answer, int &meanProgress, int &kunProgress, int &onProgress){

    // That answer was already answered
    if(correctAnswers.count(answer)) {
        kunProgress = currentExercise.getKunyomiProgress();
        onProgress = currentExercise.getOnyomiProgress();
        meanProgress = currentExercise.getMeaningProgress();
        return true;
    }

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
    default:
        break;
    }

    if(correct) {
        correctAnswers.insert(answer);
        correctAnswerSound.setPitch(INITIAL_PITCH_CORRECT_SOUND+PITCH_INCREMENT_CORRECT_SOUND*correctAnswers.size());
        correctAnswerSound.play();
    } else {
        incorrectAnswerSound.play();
    }
    return correct;
}

bool Controller::checkAnswer(std::wstring answer, int &pronProgress, int &meanProgress){

    // That answer was already answered
    if(correctAnswers.count(answer)) {
        pronProgress = currentExercise.getKunyomiProgress();
        meanProgress = currentExercise.getMeaningProgress();
        return true;
    }

    bool correct = false;

    switch(currentExercise.getExerciseType()){
    case ProgramState::WordPron:
    case ProgramState::WordMean:
        correct = WordRepository::getInstance()->checkAnswer(currentExercise, answer);
        pronProgress = currentExercise.getPronunciationProgress();
        meanProgress = currentExercise.getMeaningProgress();
        break;
    default:
        break;
    }

    if(correct) {
        correctAnswers.insert(answer);
        correctAnswerSound.setPitch(INITIAL_PITCH_CORRECT_SOUND+PITCH_INCREMENT_CORRECT_SOUND*correctAnswers.size());
        correctAnswerSound.play();
    } else {
        incorrectAnswerSound.play();
    }
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
        return WordRepository::getInstance()->allAnswered(currentExercise, correctAnswers.size());
        break;
    default:
        return false;
        break;
    }
}

void Controller::saveAndExit(){
    save();
    exit(EXIT_SUCCESS);
}

void Controller::save(){
    KanjiRepository::getInstance()->save();
    WordRepository::getInstance()->save();
}
