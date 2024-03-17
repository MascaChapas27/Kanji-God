#include "Kanji.hpp"

std::wstring Kanji::getKanji(){
    return kanji;
}

int Kanji::getGrade(){
    return grade;
}

std::set<std::wstring> Kanji::getKunyomiReadings(){
    return kunyomiReadings;
}

std::set<std::wstring> Kanji::getOnyomiReadings(){
    return onyomiReadings;
}

std::wstring Kanji::getMeaning(){
    return meaning;
}

int Kanji::getMeaningProgress(){
    return meaningProgress;
}

int Kanji::getKunyomiProgress(){
    return kunyomiProgress;
}

int Kanji::getOnyomiProgress(){
    return onyomiProgress;
}

void Kanji::setKanji(std::wstring kanji){
    this->kanji = kanji;
}

void Kanji::setGrade(int grade){
    this->grade = grade;
}

void Kanji::setKunyomiReadings(std::set<std::wstring> kunyomiReadings){
    this->kunyomiReadings = kunyomiReadings;
}

void Kanji::setOnyomiReadings(std::set<std::wstring> onyomiReadings){
    this->onyomiReadings = onyomiReadings;
}

void Kanji::setMeaning(std::wstring meaning){
    this->meaning = meaning;
}

void Kanji::setMeaningProgress(int meaningProgress){
    this->meaningProgress = meaningProgress;
}

void Kanji::setKunyomiProgress(int kunyomiProgress){
    this->kunyomiProgress = kunyomiProgress;
}

void Kanji::setOnyomiProgress(int onyomiProgress){
    this->onyomiProgress = onyomiProgress;
}
