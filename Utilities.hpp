#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

/*
    This file contains constants and other important stuff that needs to
    be global
*/

namespace util {
    // Maximum offset for a button, used when the button is not being used
    // and just exists there
    double MAX_BUTTON_TOP_OFFSET = 10;

    // Offset for a button used when the mouse hovers over the button
    double MID_BUTTON_TOP_OFFSET = 7;

    // Minimun offset for a button, used when the button was just pressed
    double MIN_TOP_OFFSET = 2;

    // Desired framerate for the game
    int FPS = 60;

    // Calculates whether a point is in a rectangle
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);
}

#endif