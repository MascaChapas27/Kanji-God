#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "Exercise.hpp"

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

        // Grade selected (expected from 1 to 6, ignored if godMode is true)
        int selectedGrade;

        // True if kanji mode is selected, false if
        // word mode (ignored if godMode is true)
        bool kanjiMode;

    public:
        // NEVER CLONE A SINGLETON
        Controller(Controller &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const Controller &) = delete;

        // Singleton-specific method to get the one and only instance
        static Controller * getInstance();

        // Sets the current grade and mode to be practiced
        void setGradeAndMode(int selectedGrade, bool kanjiMode);

        // Sets God Mode
        void setGodMode(bool godMode);

        // Returns exercise
        Exercise getExercise();
};

#endif
