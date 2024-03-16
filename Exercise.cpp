#include "Exercise.hpp"

ProgramState Exercise::getExerciseType(){
    return exerciseType;
}

int Exercise::getMeaningProgress(){
    return meaningProgress;
}

int Exercise::getKunyomiProgress(){
    return kunyomiProgress;
}

int Exercise::getOnyomiProgress(){
    return onyomiProgress;
}

int Exercise::getPronunciationProgress(){
    return pronunciationProgress;
}

std::wstring Exercise::getQuestion(){
    return question;
}

std::list<std::wstring> Exercise::getAnswers(){
    return answers;
}

std::list<std::wstring> Exercise::getKunyomiPronunciations(){
    return kunyomiPronunciations;
}

std::list<std::wstring> Exercise::getOnyomiPronunciations(){
    return onyomiPronunciations;
}

std::wstring Exercise::getWordPronunciation(){
    return wordPronunciation;
}

std::wstring Exercise::getHelp(){
    return help;
}


// SETTERS
void Exercise::setExerciseType(ProgramState exerciseType){
    this->exerciseType = exerciseType;
}

void Exercise::setMeaningProgress(int meaningProgress){
    this->meaningProgress = meaningProgress;
}

void Exercise::setKunyomiProgress(int kunyomiProgress){
    this->kunyomiProgress = kunyomiProgress;
}

void Exercise::setOnyomiProgress(int onyomiProgress){
    this->onyomiProgress = onyomiProgress;
}

void Exercise::setPronunciationProgress(int pronunciationProgress){
    this->pronunciationProgress = pronunciationProgress;
}

void Exercise::setQuestion(std::wstring question){
    this->question = question;
}

void Exercise::setAnswers(std::list<std::wstring> answers){
    this->answers = std::list<std::wstring>(answers);
}

void Exercise::setKunyomiPronunciations(std::list<std::wstring> kunyomiPronunciations){
    this->kunyomiPronunciations = kunyomiPronunciations;
}

void Exercise::setOnyomiPronunciations(std::list<std::wstring> onyomiPronunciations){
    this->onyomiPronunciations = onyomiPronunciations;
}

void Exercise::setWordPronunciation(std::wstring wordPronunciation){
    this->wordPronunciation = wordPronunciation;
}

void Exercise::setHelp(std::wstring help){
    this->help = help;
}
