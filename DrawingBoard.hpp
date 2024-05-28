#ifndef __DRAWING_BOARD_HPP__
#define __DRAWING_BOARD_HPP__

#include <SFML/Graphics.hpp>
#include <functional>

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

        // Function to be called when a stroke is finished
        std::function<void(DrawingBoard&)> finishedStrokeAction;

        // These variables make strokes a bit pointier but they avoid 234793824723 vertices
        // from being captured (60 fps = 60 vertices per second = death and destruction)

        // The frames of delay between different vertices in the same stroke
        // 0 = no delay
        // 1 = one frame delay
        // 5 = capture a vertex, wait 5 frames, capture a vertex
        int captureCountMax;

        // If set to captureCountMax, next vertex will be captured. If not, ignore and
        // make it bigger until it reaches captureCountMax
        int captureCount;

        // Color for the strokes
        sf::Color strokeColor;

        // A vector of strokes. Each stroke is a vertex array, which means that it's
        // formed by points in space. Each point is a mouse position
        std::vector<sf::VertexArray> strokes;

    public:

        DrawingBoard();

        // Sets the texture for the board and also set the origin for the sprite
        // to the center of the texture
        void setBoardTexture(sf::Texture &texture);

        // Sets the current position for the board and all its strokes
        void setPosition(double x, double y);
        void setPosition(sf::Vector2f position);

        // Sets the color for the board
        void setBoardColor(sf::Color color);

        // Sets the color for the strokes
        void setStrokeColor(sf::Color color);

        // Establishes the action to be performed if a stroke is finished
        void setFinishedStrokeAction(std::function<void(DrawingBoard&)> finishedStrokeAction);

        // Adds a stroke to the stroke list (THE ORIGIN OF ALL VERTICES MUST BE 0,0)
        void addStroke(sf::VertexArray stroke);

        // Returns the latest stroke (THE ORIGIN WILL BE 0,0 AND NOT THE CENTER OF THE BOARD)
        sf::VertexArray getLatestStroke();

        // Returns the number of strokes stored
        unsigned int getNumStrokes();

        // Erases all strokes
        void clearBoard();

        // Erases only the last stroke
        void undo();

        // Reacts to an event that happened
        virtual void notify(sf::Event &event);

        // Dumps the information about the strokes relative to the origin of
        // the board sprite (currently the center)
        void dump();

        // Draws the button
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        // Create a vertex with this position and add it to the last stroke
        // If it returns false, the vertex was out of the board and couldn't be captured
        bool captureVertex(sf::Vector2f position);

        // Ends the current stroke and does stuff
        void endStroke();
};

#endif
