#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "Exercise.hpp"
#include "ResourceHolder.hpp"
#include <SFML/Audio.hpp>
#include <set>

/*
    For a model-view-controller architecture, the controller
    is the central part. Whenever the view (buttons or the main window)
    wants to work with the model (kanji, words, progress, etc.) it
    needs to talk to the controller
*/
class Controller {
    private:
        // Constructor and destructor are made private
        // because the controller is a Singleton
        Controller(){}
        ~Controller(){}

        // Only instance
        static Controller * controller;

        // True if God Mode is selected (practice mastered elements)
        bool godMode;

        // Grade selected (expected from 1 to 5, ignored if godMode is true)
        int selectedGrade;

        // Current exercise
        Exercise currentExercise;

        // Sets of answers that were sent and were correct
        std::set<std::wstring> correctAnswers;

        // Sound that plays when the correct answer is selected
        static sf::Sound correctAnswerSound;

        // Sound that plays when an incorrect answer is selected
        static sf::Sound incorrectAnswerSound;

    public:
        // NEVER CLONE A SINGLETON
        Controller(Controller &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const Controller &) = delete;

        // Singleton-specific method to get the one and only instance
        static Controller * getInstance();

        // Sets the current grade and mode to be practiced
        void setGrade(int selectedGrade);

        // Sets God Mode to the given value
        void setGodMode(bool godMode);

        // Returns the amount of kanji that were mastered in that grade
        int getMasteredKanji(int kanjiGrade);

        // Returns the amount of total kanji in that grade
        int getTotalKanji(int kanjiGrade);

        // Returns the amount of words that were mastered in that grade
        int getMasteredWords(int wordGrade);

        // Returns the amount of total words in that grade
        int getTotalWords(int wordGrade);

        // Returns a new exercise
        Exercise getExercise();

        // Returns the current exercise
        Exercise getCurrentExercise();

        // Returns the tutorial for the current exercise
        Exercise getCurrentTutorial();

        // Checks if the kanji answer is correct and returns the progress
        bool checkAnswer(std::wstring answer, int &meanProgress, int &kunProgress, int &onProgress, int &drawProgress);

        // Checks if the word answer is correct and returns the progress
        bool checkAnswer(std::wstring answer, int &pronProgress, int &meanProgress);

        // Checks if the stroke that was sent is correct and changes it to the correct stroke
        bool checkStroke(sf::VertexArray &stroke);

        // Checks if all strokes were completed
        bool strokesCompleted(int numStrokes);

        // True if all correct answers for the current exercise were selected
        bool allAnswered();

        // Saves the progress and exit
        void saveAndExit();

        // Saves the progress but doesn't exit
        void save();
};

#endif
