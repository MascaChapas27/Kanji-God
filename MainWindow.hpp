#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include "Button.hpp"
#include "Enums.hpp"
#include "Sign.hpp"
#include "DrawingBoard.hpp"
#include "ShowingBoard.hpp"
#include <SFML/Graphics.hpp>
#include <list>

/*
    The main window. This window displays everything: the title with the
    buttons for selecting what to practice and then the exercises once the
    type of exercises was selected
*/
class MainWindow {
    private:

        // The main window
        sf::RenderWindow window;

        // Title shown when you open the program
        sf::Sprite title;

        // Sprite for the background
        sf::Sprite background;

        // Current state of the program, determines what happens
        ProgramState programState;

        // Grade shown in the grade selection button
        int grade;

        // Function that gets an exercise from the Controller and parses it and stuff
        std::function<void(Button&)> getExercise;

        // Buttons that show when you open the program
        // and it lets you choose the exercise
        std::list<Button*> menuButtons;

        // Buttons that let you answer when the answer is short
        // (kunyomi, onyomi and meaning for kanji)
        std::list<Button> shortExerciseButtons;

        // Buttons that let you answer when the answer is long
        // (meaning and pronunciation for words)
        std::list<Button> longExerciseButtons;

        // Progress for the current kanji/word
        Sign progressSign;

        // Sign for the current kanji/word
        Sign kanjiWordSign;

        // Sign for the instructions of the current exercise
        Sign instructionsSign;

        // Sign for the meaning of the current kanji for the tutorial
        Sign tutorialKanjiMeaning;

        // Sign for the meaning of the current word for the tutorial
        Sign tutorialWordMeaning;

        // Sign for the pronunciation of the current word tutorial
        Sign tutorialPronunciation;

        // Signs for the kunyomi of the current kanji tutorial
        std::vector<Sign> tutorialKunyomis;

        // Signs for the onyomi of the current kanji tutorial
        std::vector<Sign> tutorialOnyomis;

        // Sign that shows "Kunyomi" on top of the kunyomi readings
        Sign kunyomiSign;

        // Sign that shows "Onyomi" on top of the kunyomi readings
        Sign onyomiSign;

        // Board that contains the stroke order for the stroke tutorial
        ShowingBoard strokeTutorialBoardShow;

        // Board that allows the user to practice the strokes in a stroke tutorial
        DrawingBoard strokeTutorialBoardDraw;

        // Board that allows the user to draw kanjis in an exercise
        DrawingBoard strokeExerciseBoard;

        // Button to continue when the tutorial has been completed
        Button continueButton;

        // Button that allows you to go back to the main menu
        Button mainMenuButton;

        // Button that allows you to save the progress
        Button saveButton;

        // Button that shows the tutorial page for the current exercise
        Button helpButton;

        // Function that updates the amount of mastered/total exercises in the main menu button
        void updateMasteredCount(Button &gradeSelector);

    public:

        MainWindow();

        // Makes the window start working
        void start();
};

#endif
