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

void Controller::setGrade(int selectedGrade){
    this->selectedGrade = selectedGrade;
    this->godMode = false;
}

void Controller::setGodMode(bool godMode){
    this->godMode = godMode;
}

int Controller::getMasteredKanji(int kanjiGrade){
    return KanjiRepository::getInstance()->getMasteredKanji(kanjiGrade);
}

int Controller::getTotalKanji(int kanjiGrade){
    return KanjiRepository::getInstance()->getTotalKanji(kanjiGrade);
}

int Controller::getMasteredWords(int wordGrade){
    return WordRepository::getInstance()->getMasteredWords(wordGrade);
}

int Controller::getTotalWords(int wordGrade){
    return WordRepository::getInstance()->getTotalWords(wordGrade);
}


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
        } while(numAttempts <= 2 && exercise.getExerciseType() == ProgramState::TitleScreen);
    } else {
        int random = rand()%2;
        // First we check if the selected exercise is a word exercise
        if(random){
            exercise = WordRepository::getInstance()->getExercise(selectedGrade);
        }

        // Maybe the selected exercise was a word exercise that failed, or was a
        // genuine kanji exercise from the beginning
        if(!random || exercise.getExerciseType() == ProgramState::TitleScreen){
            exercise = KanjiRepository::getInstance()->getExercise(selectedGrade);
        }
    }
    /*
    } else if(kanjiMode){
        exercise = KanjiRepository::getInstance()->getExercise(selectedGrade);
    } else{
        exercise = WordRepository::getInstance()->getExercise(selectedGrade);
    }
    */

    currentExercise = exercise;
    return exercise;
}

Exercise Controller::getCurrentExercise(){
    return currentExercise;
}

Exercise Controller::getCurrentTutorial(){
    Exercise e;

    switch(currentExercise.getExerciseType()){
        case ProgramState::KanjiKun:
        case ProgramState::KanjiOn:
        case ProgramState::KanjiMean:
            e = KanjiRepository::getInstance()->getTutorial(currentExercise.getHashCode());
            break;
        case ProgramState::WordMean:
        case ProgramState::WordPron:
            e = WordRepository::getInstance()->getTutorial(currentExercise.getHashCode());
            break;
        default:
            break;
    }
    return e;
}

bool Controller::checkAnswer(std::wstring answer, int &meanProgress, int &kunProgress, int &onProgress, int &drawProgress){

    // That answer was already answered
    if(correctAnswers.count(answer)) {
        kunProgress = currentExercise.getKunyomiProgress();
        onProgress = currentExercise.getOnyomiProgress();
        meanProgress = currentExercise.getMeaningProgress();
        drawProgress = currentExercise.getDrawingProgress();
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
        drawProgress = currentExercise.getDrawingProgress();
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

bool Controller::checkStroke(sf::VertexArray &stroke){
    stroke.clear();
    stroke.append(sf::Vertex(sf::Vector2f(rand()%50,rand()%50)));
    stroke.append(sf::Vertex(sf::Vector2f(rand()%50,rand()%50)));

    bool correct = rand()%2;

    if(correct){
        correctAnswerSound.play();
    } else {
        incorrectAnswerSound.play();
    }

    return correct;
}

bool Controller::strokesCompleted(int numStrokes){
    return numStrokes == 10;
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
