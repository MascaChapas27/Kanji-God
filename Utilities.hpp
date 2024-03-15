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

// Base color for the buttons
const sf::Color BUTTON_COLOR_NORMAL = sf::Color(150,150,150);

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

namespace util {
    // Calculates whether a point is in a rectangle
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);
}

#endif
