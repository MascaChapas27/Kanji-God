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

// When deciding if a font is too bug, what percentage of the length and width of
// the button should the text have. For example, 1.0 means that the text will fit so
// that its bigger dimension (width or leight) is exactly the same as the button's
// (maybe a bit less)
const double TEXT_IN_BUTTON_MAX_RATIO = 0.8;

// Color for the font used in buttons and signs
const sf::Color TEXT_COLOR = sf::Color(200,200,200);

// Color for the grade 1 buttons
const sf::Color GRADE_1_COLOR = sf::Color(80,80,80);

// Color for the grade 2 buttons
const sf::Color GRADE_2_COLOR = sf::Color(75,75,75);

// Color for the grade 3 buttons
const sf::Color GRADE_3_COLOR = sf::Color(70,70,70);

// Color for the grade 4 buttons
const sf::Color GRADE_4_COLOR = sf::Color(65,65,65);

// Color for the grade 5 buttons
const sf::Color GRADE_5_COLOR = sf::Color(60,60,60);

// Color for the grade 6 buttons
const sf::Color GRADE_6_COLOR = sf::Color(55,55,55);

// In the title screen, distance between buttons vertically
const int TITLE_BUTTONS_VERTICAL_DISTANCE = 60;

// Position for the grade 1 buttons
const int GRADE_1_KANJI_X = 150;
const int GRADE_1_KANJI_Y = 260;
const int GRADE_1_WORD_X = 300;
const int GRADE_1_WORD_Y = GRADE_1_KANJI_Y;

// Position for the grade 2 buttons
const int GRADE_2_KANJI_X = GRADE_1_KANJI_X;
const int GRADE_2_KANJI_Y = GRADE_1_KANJI_Y + TITLE_BUTTONS_VERTICAL_DISTANCE;
const int GRADE_2_WORD_X = GRADE_1_WORD_X;
const int GRADE_2_WORD_Y = GRADE_2_KANJI_Y;

// Position for the grade 3 buttons
const int GRADE_3_KANJI_X = GRADE_1_KANJI_X;
const int GRADE_3_KANJI_Y = GRADE_2_KANJI_Y + TITLE_BUTTONS_VERTICAL_DISTANCE;
const int GRADE_3_WORD_X = GRADE_1_WORD_X;
const int GRADE_3_WORD_Y = GRADE_1_KANJI_Y;

// Position for the grade 4 buttons
const int GRADE_4_KANJI_X = GRADE_1_KANJI_X;
const int GRADE_4_KANJI_Y = GRADE_3_KANJI_Y + TITLE_BUTTONS_VERTICAL_DISTANCE;
const int GRADE_4_WORD_X = GRADE_1_WORD_X;
const int GRADE_4_WORD_Y = GRADE_1_KANJI_Y;

// Position for the grade 5 buttons
const int GRADE_5_KANJI_X = GRADE_1_KANJI_X;
const int GRADE_5_KANJI_Y = GRADE_4_KANJI_Y + TITLE_BUTTONS_VERTICAL_DISTANCE;
const int GRADE_5_WORD_X = GRADE_1_WORD_X;
const int GRADE_5_WORD_Y = GRADE_1_KANJI_Y;

// Position for the grade 6 buttons
const int GRADE_6_KANJI_X = GRADE_1_KANJI_X;
const int GRADE_6_KANJI_Y = GRADE_5_KANJI_Y + TITLE_BUTTONS_VERTICAL_DISTANCE;
const int GRADE_6_WORD_X = GRADE_1_WORD_X;
const int GRADE_6_WORD_Y = GRADE_1_KANJI_Y;

namespace util {
    // Calculates whether a point is in a rectangle
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);
}

#endif
