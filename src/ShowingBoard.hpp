#ifndef __SHOWING_BOARD_HPP__
#define __SHOWING_BOARD_HPP__

#include "DrawingBoard.hpp"
#include <SFML/Graphics.hpp>
#include <map>

/*
    This class is like a DrawingBoard but it can't be edited by the user
*/
class ShowingBoard : public DrawingBoard {

    private:
        // Stroke that will be shown (strokes before this one will alse be shown but the
        // current one will have a big circle indicating the initial point of the stroke)
        int currentStroke;

    public:

        // The constructor sets the texture for the sprite
        ShowingBoard(const sf::Texture& texture);

        // This function won't do anything
        void notify(sf::Event &event);

        // Draws the board with a big circle on the first vertex of the current stroke
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        // Returns to the previous stroke
        void undo();

        // Advance to the next stroke
        void nextStroke();

        // Sets the strokes to be shown and resets the current stroke counter
        // (THE STROKES MUST HAVE (0,0) AS THEIR ORIGIN)
        void setStrokes(std::vector<sf::VertexArray> strokes);
};

#endif
