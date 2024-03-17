#ifndef __KANJI_HPP__
#define __KANJI_HPP__

#include <string>
#include <vector>

/*
    This class contains information for one kanji
*/
class Kanji{
    private:
        // The kanji itself represented by a wstring
        std::wstring kanji;

        // Vector of kunyomi readings
        std::vector<std::wstring> kunyomiReadings;

        // Vector of onyomi readings
        std::vector<std::wstring> onyomiReadings;

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
        std::vector<std::wstring> getKunyomiReadings();
        std::vector<std::wstring> getOnyomiReadings();
        std::wstring getMeaning();
        int getMeaningProgress();
        int getKunyomiProgress();
        int getOnyomiProgress();

        // SETTERS
        void setKanji(std::wstring kanji);
        void setKunyomiReadings(std::vector<std::wstring> kunyomiReadings);
        void setOnyomiReadings(std::vector<std::wstring> onyomiReadings);
        void getMeaning(std::wstring meaning);
        void setMeaningProgress(int meaningProgress);
        void setKunyomiProgress(int kunyomiProgress);
        void setOnyomiProgress(int onyomiProgress);
};

#endif
