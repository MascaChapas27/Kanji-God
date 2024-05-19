#ifndef __EXERCISE_HPP__
#define __EXERCISE_HPP__

#include "Enums.hpp"
#include <string>
#include <set>

/*
    This class defines exercises and tutorials that are passed from the
    controller to the view. Instead of returning 117398143 lists and
    changing parameters, the controller simply returns an Exercise
*/
class Exercise {
    private:
        // Type of the exercise
        ProgramState exerciseType;

        // Hash code for the kanji or word
        unsigned long hashCode;

        // Progress for the meaning
        int meaningProgress;

        // Progress for kunyomi and onyomi (only in kanji exercises)
        int kunyomiProgress;
        int onyomiProgress;

        // Progress for the pronunciation (only in word exercises)
        int pronunciationProgress;

        // Kanji or word that is being asked or taught
        std::wstring question;

        // Meaning for the kanji or word that is being taught
        std::wstring tutorialMeaning;

        // Vector of possible answers (only if it's a question)
        std::set<std::wstring> answers;

        // Vectors of kunyomi and onyomi pronunciations (only if it's a kanji tutor)
        std::set<std::wstring> kunyomiPronunciations;
        std::set<std::wstring> onyomiPronunciations;

        // Pronunciation for the word (only if it's a word tutor)
        std::wstring wordPronunciation;

        // Help for the sign under the question
        std::wstring help;

    public:
        // GETTERS
        ProgramState getExerciseType();
        unsigned long getHashCode();
        int getMeaningProgress();
        int getKunyomiProgress();
        int getOnyomiProgress();
        int getPronunciationProgress();
        std::wstring getQuestion();
        std::wstring getTutorialMeaning();
        std::set<std::wstring> getAnswers();
        std::set<std::wstring> getKunyomiPronunciations();
        std::set<std::wstring> getOnyomiPronunciations();
        std::wstring getWordPronunciation();
        std::wstring getHelp();

        // SETTERS
        void setExerciseType(ProgramState exerciseType);
        void setHashCode(unsigned long hashCode);
        void setMeaningProgress(int meaningProgress);
        void setKunyomiProgress(int kunyomiProgress);
        void setOnyomiProgress(int onyomiProgress);
        void setPronunciationProgress(int pronunciationProgress);
        void setTutorialMeaning(std::wstring tutorialMeaning);
        void setQuestion(std::wstring question);
        void setAnswers(std::set<std::wstring> answers);
        void setKunyomiPronunciations(std::set<std::wstring> kunyomiPronunciations);
        void setOnyomiPronunciations(std::set<std::wstring> onyomiPronunciations);
        void setWordPronunciation(std::wstring wordPronunciation);
        void setHelp(std::wstring help);
};

#endif
