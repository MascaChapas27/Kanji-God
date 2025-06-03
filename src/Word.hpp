#ifndef __WORD_HPP__
#define __WORD_HPP__

#include <string>
#include <set>

/*
    This class contains information for one word
*/
class Word{
    private:
        // The word itself represented by a wstring
        std::wstring word;

        // Grade that this word is taught on
        int grade;

        // Pronunciation for the word
        std::wstring pronunciation;

        // Meaning of the word
        std::wstring meaning;

        // Progress for the pronunciation of the wprd
        int pronunciationProgress;

        // Progress for the meaning of the word
        int meaningProgress;
    
    public:

        // GETTERS
        std::wstring getWord();
        int getGrade();
        std::wstring getPronunciation();
        std::wstring getMeaning();
        int getPronunciationProgress();
        int getMeaningProgress();

        // SETTERS
        void setWord(std::wstring word);
        void setGrade(int grade);
        void setPronunciation(std::wstring pronunciation);
        void setMeaning(std::wstring meaning);
        void setPronunciationProgress(int pronunciationProgress);
        void setMeaningProgress(int meaningProgress);
};

#endif
