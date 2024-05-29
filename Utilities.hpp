#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

/*
    This file contains constants and other important stuff that need to
    be global
*/

// Type for the hash code used to identify kanjis and words
typedef unsigned long long hash_t;

// Size for the main window
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Title for the main window
const std::string WINDOW_TITLE = "amai";

// Position for the title
const int TITLE_X = WINDOW_WIDTH/2;
const int TITLE_Y = WINDOW_HEIGHT/4;

// Maximum offset for a button, used when the button is not being used
// and just exists there
const double MAX_BUTTON_TOP_OFFSET = 10;

// Offset for a button used when the mouse hovers over the button
const double MID_BUTTON_TOP_OFFSET = 8;

// Minimun offset for a button, used when the button was just pressed
const double MIN_BUTTON_TOP_OFFSET = 2;

// When the depth of a button moves, it proceeds to the new position by taking the
// remaining distance and advancing a fraction of that distance. The bigger the value
// of this constant is, the smaller that fraction will be, so 1.0 means instant movement
const double BUTTON_PRESS_SPEED = 5.0;

// Desired framerate for the game
const int FPS = 60;

// Font size all fonts start at. It then gets smaller to fit in the button or label
const int INITIAL_FONT_SIZE = 70;

// Minumum font size so that letters are readable and dont shrink forever
const double MIN_FONT_SIZE = 15;

// Size in pixels of the margin that a text leaves in a button or sign
const double BUTTON_TEXT_MARGIN = 40;

// Color for the font used in buttons and signs
const sf::Color TEXT_COLOR = sf::Color(255,255,255);

// Base color for the buttons
const sf::Color BUTTON_COLOR_NORMAL = sf::Color(150,150,150);

// Color for correct answer
const sf::Color BUTTON_COLOR_CORRECT = sf::Color(0,150,0);

// Color for incorrect answer
const sf::Color BUTTON_COLOR_INCORRECT = sf::Color(150,0,0);

// Color for the continue button
const sf::Color CONTINUE_COLOR = sf::Color(70,70,150);

// Color for the save button when you can save
const sf::Color SAVE_COLOR = sf::Color(100,100,170);

// Color for the save button when you already saved
const sf::Color SAVED_COLOR = sf::Color(200,200,200);

// Color for the help button
const sf::Color HELP_COLOR = sf::Color(100,100,170);

// Color for the board that shows the strokes in the tutorial
const sf::Color BOARD_TUTORIAL_SHOW_COLOR = sf::Color(50,50,50);

// Color for the boards that let the user draw
const sf::Color BOARD_DRAW_COLOR = sf::Color(255,255,255);

// Color for the strokes in the board that shows the strokes in the tutorial
const sf::Color STROKE_TUTORIAL_SHOW_COLOR = sf::Color(255,255,255);

// Color for the strokes drawn by the user
const sf::Color STROKE_DRAW_COLOR = sf::Color(0,0,0);

// In the title screen, distance between buttons vertically
const int TITLE_BUTTONS_VERTICAL_DISTANCE = 60;

// Position of the kanji button in the main menu
const int GRADE_MENU_BUTTON_X = WINDOW_WIDTH/3;
const int GRADE_MENU_BUTTON_Y = 400;

// Position of the god mode button in the main menu
const int GODMODE_MENU_BUTTON_X = 2*WINDOW_WIDTH/3;
const int GODMODE_MENU_BUTTON_Y = GRADE_MENU_BUTTON_Y;

// Position of the arrows for the grade selection button in the main menu
const int MENU_ARROW_LEFT_X = GRADE_MENU_BUTTON_X - 75;
const int MENU_ARROW_LEFT_Y = GRADE_MENU_BUTTON_Y + 120;
const int MENU_ARROW_RIGHT_X = GRADE_MENU_BUTTON_X + 75;
const int MENU_ARROW_RIGHT_Y = MENU_ARROW_LEFT_Y;

// Position for the sign that has the kanji/word that is currently being asked/taught
const int KANJI_WORD_SIGN_X = 8*WINDOW_WIDTH/10;
const int KANJI_WORD_SIGN_Y = WINDOW_HEIGHT/2;

// Position for the sign that shows the progress for learning a kanji/word
const int PROGRESS_SIGN_X = KANJI_WORD_SIGN_X;
const int PROGRESS_SIGN_Y = WINDOW_HEIGHT/6;

// Position for the sign that shows the instructions for the current exercise
const int INSTRUCTIONS_SIGN_X = KANJI_WORD_SIGN_X;
const int INSTRUCTIONS_SIGN_Y = 5*WINDOW_HEIGHT/6;

// Position for the short buttons in exercises
const int SHORT_EXERCISE_BUTTON_X[9] = {115,267,420,
                                        115,267,420,
                                        115,267,420};
const int SHORT_EXERCISE_BUTTON_Y[9] = {60+WINDOW_HEIGHT/4,60+WINDOW_HEIGHT/4,60+WINDOW_HEIGHT/4,
                                        60+WINDOW_HEIGHT/2,60+WINDOW_HEIGHT/2,60+WINDOW_HEIGHT/2,
                                        60+3*WINDOW_HEIGHT/4,60+3*WINDOW_HEIGHT/4,60+3*WINDOW_HEIGHT/4};

// Position for the long buttons in exercises
const int LONG_EXERCISE_BUTTON_X[6] = {150,385,
                                       150,385,
                                       150,385};
const int LONG_EXERCISE_BUTTON_Y[6] = {60+WINDOW_HEIGHT/4,60+WINDOW_HEIGHT/4,
                                        60+WINDOW_HEIGHT/2,60+WINDOW_HEIGHT/2,
                                        60+3*WINDOW_HEIGHT/4,60+3*WINDOW_HEIGHT/4};


// Position for the tutorial sign that contains the meaning for the kanji
const int KANJI_MEANING_SIGN_X = 7*WINDOW_WIDTH/20;
const int KANJI_MEANING_SIGN_Y = WINDOW_HEIGHT/8;

// Position for the tutorial sign that contains the meaning for the word
const int WORD_MEANING_SIGN_X = 7*WINDOW_WIDTH/20;
const int WORD_MEANING_SIGN_Y = WINDOW_HEIGHT/3;

// Position for the tutorial sign that says "Kunyomi"
const int KUNYOMI_SIGN_X = KANJI_MEANING_SIGN_X-125;
const int KUNYOMI_SIGN_Y = KANJI_MEANING_SIGN_Y+110;

// Position for the tutorial sign that says "Onyomi"
const int ONYOMI_SIGN_X = KANJI_MEANING_SIGN_X+125;
const int ONYOMI_SIGN_Y = KUNYOMI_SIGN_Y;

// Position for the signs that contain the kunyomi readings in the tutorial
const int KUN_READING_X[6] = {KUNYOMI_SIGN_X-60,KUNYOMI_SIGN_X+60,
                              KUNYOMI_SIGN_X-60,KUNYOMI_SIGN_X+60,
                              KUNYOMI_SIGN_X-60,KUNYOMI_SIGN_X+60};
const int KUN_READING_Y[6] = {KUNYOMI_SIGN_Y+110,KUNYOMI_SIGN_Y+110,
                              KUNYOMI_SIGN_Y+220,KUNYOMI_SIGN_Y+220,
                              KUNYOMI_SIGN_Y+330,KUNYOMI_SIGN_Y+330};

// Position for the signs that contain the onyomi readings in the tutorial
const int ON_READING_X[6] = {ONYOMI_SIGN_X-60,ONYOMI_SIGN_X+60,
                             ONYOMI_SIGN_X-60,ONYOMI_SIGN_X+60,
                             ONYOMI_SIGN_X-60,ONYOMI_SIGN_X+60};
const int ON_READING_Y[6] = {ONYOMI_SIGN_Y+110,ONYOMI_SIGN_Y+110,
                             ONYOMI_SIGN_Y+220,ONYOMI_SIGN_Y+220,
                             ONYOMI_SIGN_Y+330,ONYOMI_SIGN_Y+330};

// Position for the sign that contains the pronunciation for the word in the tutorial
const int WORD_PRON_SIGN_X = 7*WINDOW_WIDTH/20;
const int WORD_PRON_SIGN_Y = 2*WINDOW_HEIGHT/3;

//Position for the button that takes you to the main menu
const int BACK_MENU_BUTTON_X = 60;
const int BACK_MENU_BUTTON_Y = 70;

//Position for the button that saves the current progress
const int SAVE_BUTTON_X = BACK_MENU_BUTTON_X+100;
const int SAVE_BUTTON_Y = BACK_MENU_BUTTON_Y;

//Position for the button that how help for the current exercise
const int HELP_BUTTON_X = SAVE_BUTTON_X+100;
const int HELP_BUTTON_Y = BACK_MENU_BUTTON_Y;

// Placeholder progress for something not yet taught
const int NO_PROGRESS = -1;

// Minimum progress for an exercise (that has been already taught)
const int MIN_PROGRESS = 0;

// Maximum progress for an exercise
const int MAX_PROGRESS = 100;

// Points given for correctly guessing all kunyomi readings (kind of (it's divided
// for all different answers so maybe this number divided by 6 or 5 isn't exact))
const int CORRECT_KUN_POINTS = 10;

// Points taken for incorrectly guessing a kunyomi reading
const int INCORRECT_KUN_POINTS = 20;

// Points given for correctly guessing all onyomi readings (kind of (it's divided
// for all different answers so maybe this number divided by 6 or 5 isn't exact))
const int CORRECT_ON_POINTS = CORRECT_KUN_POINTS;

// Points taken for incorrectly guessing an onyomi reading
const int INCORRECT_ON_POINTS = INCORRECT_KUN_POINTS;

// Points given for correctly guessing a kanji meaning
const int CORRECT_KANJIMEAN_POINTS = CORRECT_KUN_POINTS;

// Points taken for incorrectly guessing a kanji meaning
const int INCORRECT_KANJIMEAN_POINTS = INCORRECT_KUN_POINTS;

// Points given for correctly guessing a word pronunciation
const int CORRECT_PRON_POINTS = 10;

// Points taken for incorrectly guessing a word pronunciation
const int INCORRECT_PRON_POINTS = 20;

// Points given for correctly guessing a word meaning
const int CORRECT_WORDMEAN_POINTS = CORRECT_PRON_POINTS;

// Points taken for incorrectly guessing a word meaning
const int INCORRECT_WORDMEAN_POINTS = INCORRECT_PRON_POINTS;

// Initial pitch for the correct answer sound
const double INITIAL_PITCH_CORRECT_SOUND = 1.3;

// Pitch increment for the correct answer sound for every correct answer
const double PITCH_INCREMENT_CORRECT_SOUND = 0.1;

// Position for the board that shows the strokes in the tutorial
const double BOARD_TUTORIAL_SHOW_X = WINDOW_WIDTH/3;
const double BOARD_TUTORIAL_SHOW_Y = 6*WINDOW_HEIGHT/20;

// Position for the board that lets the user practice strokes in the tutorial
const double BOARD_TUTORIAL_DRAW_X = BOARD_TUTORIAL_SHOW_X;
const double BOARD_TUTORIAL_DRAW_Y = 14*WINDOW_HEIGHT/20;

// Position for the board used in exercises
const double BOARD_EXERCISE_DRAW_X = BOARD_TUTORIAL_DRAW_X;
const double BOARD_EXERCISE_DRAW_Y = WINDOW_HEIGHT/2;

// When comparing the length of two strokes, the minimum and maximum
// ratio that is considered correct
const double MIN_STROKE_SIZE_RATIO = 0.6;
const double MAX_STROKE_SIZE_RATIO = 1.4;

// Thickness for strokes
const double STROKE_THICKNESS = 5;

// For the first and last vertices of a stroke, the maximum distance in pixels
// that is considered correct
const double MAX_STROKE_VERTEX_DIST = 40;

// How many frames to wait between vertices when drawing (in Windows it works differently)
#ifdef _WIN32
const int VERTEX_DELAY = 2;
#else
const int VERTEX_DELAY = 2;
#endif

namespace util {
    // Calculates whether a point is in a rectangle
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);

    // Tells if you should learn new content or practice
    bool shouldLearnNewContent(int newContent, bool isWord);

    // Makes a sound based on the SoundID of that sound
    sf::Sound initializeSound(SoundID soundId);

    // Replaces all line feeds with spaces so that answers that needed to be shrunk
    // can be properly checked and don't contain extra line feeds
    std::wstring trimLineFeeds(std::wstring answer);

    // Calculates a hash code given a wstring
    hash_t hash(std::wstring wstring);

    // Gets a wstring and a character and returns a vector of substrings separated by that character
    // (the character itself is not included in any substring)
    std::vector<std::wstring> split(std::wstring wstring, wchar_t separator);

    // Given two points in space, returns the euclidean distance between them
    double euclideanDistance(sf::Vector2f a, sf::Vector2f b);
}

#endif
