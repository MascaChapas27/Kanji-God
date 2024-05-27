#ifndef __SHOWING_BOARD_HPP__
#define __SHOWING_BOARD_HPP__

#include "DrawingBoard.hpp"

/*
    This class is like a DrawingBoard but it can't be edited by the user
*/

class ShowingBoard : public DrawingBoard {

    public:
        // This function won't do anything
        void notify(sf::Event &event);
};

#endif
