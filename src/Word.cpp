#include "Word.hpp"

std::wstring Word::getWord(){
    return word;
}

int Word::getGrade(){
    return grade;
}

std::wstring Word::getPronunciation(){
    return pronunciation;
}

std::wstring Word::getMeaning(){
    return meaning;
}

int Word::getPronunciationProgress(){
    return pronunciationProgress;
}

int Word::getMeaningProgress(){
    return meaningProgress;
}


void Word::setWord(std::wstring word){
    this->word = word;
}

void Word::setGrade(int grade){
    this->grade = grade;
}

void Word::setPronunciation(std::wstring pronunciation){
    this->pronunciation = pronunciation;
}

void Word::setMeaning(std::wstring meaning){
    this->meaning = meaning;
}

void Word::setPronunciationProgress(int pronunciationProgress){
    this->pronunciationProgress = pronunciationProgress;
}

void Word::setMeaningProgress(int meaningProgress){
    this->meaningProgress = meaningProgress;
}
