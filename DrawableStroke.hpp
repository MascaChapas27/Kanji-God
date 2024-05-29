#ifndef __DRAWABLE_STROKE_HPP__
#define __DRAWABLE_STROKE_HPP__

#include <SFML/Graphics.hpp>

/*
    I tried drawing strokes as sf::LineStrip but it was too thin so I googled how to
    make thicker line strips and https://github.com/SFML/SFML/wiki/source:-line-segment-with-thickness
    was the answer
*/
class DrawableStroke : public sf::Drawable {

    private:
        // Four vertices in a drawable stroke
        sf::Vertex vertices[4];

        // Thickness for the stroke
        float thickness;

        // Color for the stroke
        sf::Color color;

    public:
        // Creates a drawable stroke based on two points, a color and a thickness
        DrawableStroke(const sf::Vector2f point1, const sf::Vector2f point2, sf::Color color, double thickness);

        // Draws the stroke
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // __DRAWABLE_STROKE_HPP__
