#ifndef __DRAWING_BOARD_HPP__
#define __DRAWING_BOARD_HPP__

#include <SFML/Graphics.hpp>

/*
    This class defines a drawing board formed by an image for the background
    and an area to draw.
*/
class DrawingBoard : public sf::Drawable{
    private:
        // Sprite for the board
        sf::Sprite boardSprite;

        // If set to true, start a new stroke and register every vertex
        // If set to false, end the current stroke and stop registering vertices
        bool currentlyDrawing;

        // A vector of strokes. Each stroke is a vertex array, which means that it's
        // formed by points in space. Each point is a mouse position
        std::vector<sf::VertexArray> strokes;

    public:

        DrawingBoard();

        // Sets the texture for the board
        void setBoardTexture(sf::Texture &texture);

        // Sets the current position for the board and all its strokes
        void setPosition(double x, double y);
        void setPosition(sf::Vector2f position);

        // Sets the color for the board
        void setBoardColor(sf::Color color);

        // Reacts to an event that happened
        void notify(sf::Event &event);

        // Draws the button
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
