#ifndef __POINT_BY_POINT_BOARD_HPP__
#define __POINT_BY_POINT_BOARD_HPP__

#include "DrawingBoard.hpp"


/*
    This is like a drawing board but the vertices are drawn by clicking point by point instead of drawing
    full strokes.
*/
class PointByPointBoard : public DrawingBoard {

    protected:
        // Current position of the mouse, used to shot an extra vertex when drawing
        sf::Vector2f mousePosition;

    public:

        // Undos just a vertex instead of a whole stroke
        void undo();

        // Captures vertices click by click
        void notify(sf::Event &event);

        // Also draws a vertex in the mouse's position if drawing
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:

        // Doesn't use the capture count
        bool captureVertex(sf::Vector2f position);
};

#endif
