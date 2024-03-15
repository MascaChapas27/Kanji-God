#ifndef __EXERCISE_HPP__
#define __EXERCISE_HPP__

#include "Enums.hpp"
#include <string>
#include <list>

/*
    This class defines exercises and tutorials that are passed from the
    controller to the view. Instead of returning 117398143 lists and
    changing parameters, the controller simply returns an Exercise
*/
class Exercise {
    private:
        // Type of the exercise
        ProgramState exerciseType;

        // Progress for the meaning
        int meaningProgress;

        // Progress for kunyomi and onyomi (only in kanji exercises)
        int kunyomiProgress;
        int onyomiProgress;

        // Progress for the pronunciation (only in word exercises)
        int pronunciationProgress;

        // Kanji or word that is being asked or taught
        std::wstring question;

        // List of possible answers (only if it's a question)
        std::list<std::wstring> answers;

        // List of kunyomi and onyomi pronunciations (only if it's a kanji tutor)
        std::list<std::wstring> kunyomiPronunciations;
        std::list<std::wstring> onyomiPronunciations;

        // Pronunciation for the word (only if it's a word tutor)
        std::wstring wordPronunciation;

        // Help for the sign under the question
        std::wstring help;

    public:
        // GETTERS
        ProgramState getExerciseType();
        int getMeaningProgress();
        int getKunyomiProgress();
        int getOnyomiProgress();
        int getPronunciationProgress();
        std::wstring getQuestion();
        std::list<std::wstring> getAnswers();
        std::list<std::wstring> getKunyomiPronunciations();
        std::list<std::wstring> getOnyomiPronunciations();
        std::wstring getWordPronunciation();
        std::wstring getHelp();

        // SETTERS
        void setExerciseType(ProgramState exerciseType);
        void setMeaningProgress(int meaningProgress);
        void setKunyomiProgress(int kunyomiProgress);
        void setOnyomiProgress(int onyomiProgress);
        void setPronunciationProgress(int pronunciationProgress);
        void setQuestion(std::wstring question);
        void setAnswers(std::list<std::wstring> answers);
        void setKunyomiPronunciations(std::list<std::wstring> kunyomiPronunciations);
        void setOnyomiPronunciations(std::list<std::wstring> onyomiPronunciations);
        void setWordPronunciation(std::wstring wordPronunciation);
        void setHelp(std::wstring help);
};

#endif
