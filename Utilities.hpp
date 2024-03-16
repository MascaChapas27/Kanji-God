#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

#include <SFML/Graphics.hpp>

/*
    This file contains constants and other important stuff that need to
    be global
*/

// Size for the main window
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Title for the main window
const std::string WINDOW_TITLE = "amai";

// Position for the title
const int TITLE_X = 80;
const int TITLE_Y = 20;

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
const int INITIAL_FONT_SIZE = 100;

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

// In the title screen, distance between buttons vertically
const int TITLE_BUTTONS_VERTICAL_DISTANCE = 60;

// Position of the kanji button in the main menu
const int KANJI_MENU_BUTTON_X = WINDOW_WIDTH/4;
const int KANJI_MENU_BUTTON_Y = 400;

// Position of the word button in the main menu
const int WORD_MENU_BUTTON_X = WINDOW_WIDTH/2;
const int WORD_MENU_BUTTON_Y = KANJI_MENU_BUTTON_Y;

// Position of the arrows for the kanji button in the main menu
const int KANJI_MENU_ARROW_LEFT_X = KANJI_MENU_BUTTON_X - 50;
const int KANJI_MENU_ARROW_LEFT_Y = KANJI_MENU_BUTTON_Y + 120;
const int KANJI_MENU_ARROW_RIGHT_X = KANJI_MENU_BUTTON_X + 50;
const int KANJI_MENU_ARROW_RIGHT_Y = KANJI_MENU_ARROW_LEFT_Y;

// Position of the arrows for the word button in the main menu
const int WORD_MENU_ARROW_LEFT_X = WORD_MENU_BUTTON_X - 50;
const int WORD_MENU_ARROW_LEFT_Y = KANJI_MENU_ARROW_LEFT_Y;
const int WORD_MENU_ARROW_RIGHT_X = WORD_MENU_BUTTON_X + 50;
const int WORD_MENU_ARROW_RIGHT_Y = KANJI_MENU_ARROW_LEFT_Y;

// Position for the sign that has the kanji/word that is currently being asked/taught
const int KANJI_WORD_SIGN_X = 8*WINDOW_WIDTH/10;
const int KANJI_WORD_SIGN_Y = WINDOW_HEIGHT/2;

// Position for the sign that shows the progress for learning a kanji/word
const int PROGRESS_SIGN_X = KANJI_WORD_SIGN_X;
const int PROGRESS_SIGN_Y = WINDOW_HEIGHT/6;

// Position for the sign that shows the instructions for the current exercise
const int INSTRUCTIONS_SIGN_X = KANJI_WORD_SIGN_X;
const int INSTRUCTIONS_SIGN_Y = 5*WINDOW_HEIGHT/6;

// Position for the short buttons used when asking for kunyomi and onyomi for a single kanji
const int SHORT_EXERCISE_BUTTON_X[9] = {100,250,400,
                                        100,250,400,
                                        100,250,400};
const int SHORT_EXERCISE_BUTTON_Y[9] = {WINDOW_HEIGHT/4,WINDOW_HEIGHT/4,WINDOW_HEIGHT/4,
                                        WINDOW_HEIGHT/2,WINDOW_HEIGHT/2,WINDOW_HEIGHT/2,
                                        3*WINDOW_HEIGHT/4,3*WINDOW_HEIGHT/4,3*WINDOW_HEIGHT/4};

namespace util {
    // Calculates whether a point is in a rectangle
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);

    // Tells if you should learn a new kanji or practice an existing one
    bool shouldLearnNewKanji(int newKanji);
}

#endif
