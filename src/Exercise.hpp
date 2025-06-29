#ifndef __EXERCISE_HPP__
#define __EXERCISE_HPP__

#include "Enums.hpp"
#include "Utilities.hpp"
#include <string>
#include <set>
#include <SFML/Graphics.hpp>

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
        hash_t hashCode;

        // Progress for the meaning
        int meaningProgress;

        // Progress for kunyomi and onyomi (only in kanji exercises)
        int kunyomiProgress;
        int onyomiProgress;

        // Progress for the pronunciation (only in word exercises)
        int pronunciationProgress;

        // Progress for drawing the strokes (only in stroke exercises)
        int drawingProgress;

        // Kanji or word that is being asked or taught
        std::wstring question;

        // Meaning for the kanji or word that is being taught
        std::wstring tutorialMeaning;

        // Set of possible answers (only if it's a question)
        std::set<std::wstring> answers;

        // Vector of strokes (represented by arrays of vertices)
        std::vector<sf::VertexArray> strokes;

        // Sets of kunyomi and onyomi pronunciations (only if it's a kanji tutor)
        std::set<std::wstring> kunyomiPronunciations;
        std::set<std::wstring> onyomiPronunciations;

        // Pronunciation for the word (only if it's a word tutor)
        std::wstring wordPronunciation;

        // Help for the sign under the question
        std::wstring help;

    public:
        // GETTERS
        ProgramState getExerciseType();
        hash_t getHashCode();
        int getMeaningProgress();
        int getKunyomiProgress();
        int getOnyomiProgress();
        int getPronunciationProgress();
        int getDrawingProgress();
        std::wstring getQuestion();
        std::wstring getTutorialMeaning();
        std::set<std::wstring> getAnswers();
        std::vector<sf::VertexArray> getStrokes();
        std::set<std::wstring> getKunyomiPronunciations();
        std::set<std::wstring> getOnyomiPronunciations();
        std::wstring getWordPronunciation();
        std::wstring getHelp();

        // SETTERS
        void setExerciseType(ProgramState exerciseType);
        void setHashCode(hash_t hashCode);
        void setMeaningProgress(int meaningProgress);
        void setKunyomiProgress(int kunyomiProgress);
        void setOnyomiProgress(int onyomiProgress);
        void setPronunciationProgress(int pronunciationProgress);
        void setDrawingProgress(int drawingProgress);
        void setTutorialMeaning(std::wstring tutorialMeaning);
        void setQuestion(std::wstring question);
        void setAnswers(std::set<std::wstring> answers);
        void setStrokes(std::vector<sf::VertexArray> strokes);
        void setKunyomiPronunciations(std::set<std::wstring> kunyomiPronunciations);
        void setOnyomiPronunciations(std::set<std::wstring> onyomiPronunciations);
        void setWordPronunciation(std::wstring wordPronunciation);
        void setHelp(std::wstring help);
};

#endif
