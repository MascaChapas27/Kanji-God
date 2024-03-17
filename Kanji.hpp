#ifndef __KANJI_HPP__
#define __KANJI_HPP__

#include <string>
#include <set>

/*
    This class contains information for one kanji
*/
class Kanji{
    private:
        // The kanji itself represented by a wstring
        std::wstring kanji;

        // Grade that this kanji is taught on
        int grade;

        // Set of kunyomi readings
        std::set<std::wstring> kunyomiReadings;

        // Set of onyomi readings
        std::set<std::wstring> onyomiReadings;

        // Meaning of the kanji
        std::wstring meaning;

        // Progress for the meaning of the kanji
        int meaningProgress;

        // Progress for the kunyomi of the kanji
        int kunyomiProgress;

        // Progress for the onyomi of the kanji
        int onyomiProgress;
    
    public:

        // GETTERS
        std::wstring getKanji();
        int getGrade();
        std::set<std::wstring> getKunyomiReadings();
        std::set<std::wstring> getOnyomiReadings();
        std::wstring getMeaning();
        int getMeaningProgress();
        int getKunyomiProgress();
        int getOnyomiProgress();

        // SETTERS
        void setKanji(std::wstring kanji);
        void setGrade(int grade);
        void setKunyomiReadings(std::set<std::wstring> kunyomiReadings);
        void setOnyomiReadings(std::set<std::wstring> onyomiReadings);
        void setMeaning(std::wstring meaning);
        void setMeaningProgress(int meaningProgress);
        void setKunyomiProgress(int kunyomiProgress);
        void setOnyomiProgress(int onyomiProgress);
};

#endif
