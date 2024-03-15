#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include "Button.hpp"
#include "Enums.hpp"
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

        // Grade shown in the kanji and word buttons
        int kanjiGrade;
        int wordGrade;

        // Buttons that show when you open the program
        // and it lets you choose the exercise
        std::list<Button*> menuButtons;

        // Buttons that let you answer when the answer is short
        // (kunyomi and onyomi for one kanji)
        std::list<Button*> shortExerciseButtons;

        // Buttons that let you answer when the answer is long
        // (meaning for kanjis and words and pronunciation for words)
        std::list<Button*> longExerciseButtons;

        // Progress for the current kanji
        // ProgressSign progressKanji;

        // Progress for the current word
        // ProgressSign progressWord;

        // Sign for the current kanji/word
        // Sign kanjiWordSign;

        // Sign for the instructions of the current exercise
        // Sign instructions;

        // Sign for the meaning of the current kanji/word for
        // the tutorial
        // Sign tutorialMeaning;

        // Sign for the pronunciation of the current word tutorial
        // Sign tutorialPronunciation;

        // Signs for the kunyomi of the current kanji tutorial
        // std::list<Sign> tutorialKunyomis;

        // Signs for the onyomi of the current kanji tutorial
        // std::list<Sign> tutorialOnyomis;

    public:

        // Makes the window start working
        void start();
};

#endif
