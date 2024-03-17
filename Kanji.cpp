#include "Kanji.hpp"

std::wstring Kanji::getKanji(){
    return kanji;
}

std::vector<std::wstring> Kanji::getKunyomiReadings(){
    return kunyomiReadings;
}

std::vector<std::wstring> Kanji::getOnyomiReadings(){
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


// SETTERS
void Kanji::setKanji(std::wstring kanji){
    this->kanji = kanji;
}

void Kanji::setKunyomiReadings(std::vector<std::wstring> kunyomiReadings){
    this->kunyomiReadings = kunyomiReadings;
}

void Kanji::setOnyomiReadings(std::vector<std::wstring> onyomiReadings){
    this->onyomiReadings = onyomiReadings;
}

void Kanji::getMeaning(std::wstring meaning){
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
