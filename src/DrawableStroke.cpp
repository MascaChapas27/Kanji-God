#include "DrawableStroke.hpp"
#include <cmath>

DrawableStroke::DrawableStroke(const sf::Vector2f point1, const sf::Vector2f point2, sf::Color color, float thickness) :
    vertices(sf::PrimitiveType::TriangleStrip, 4)
{
    this->color = color;
    this->thickness = thickness;

    if(point1 == point2){
        
    }

    sf::Vector2f direction = point2 - point1;
    sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
    sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

    sf::Vector2f offset;
    offset.x = (thickness/2.f)*unitPerpendicular.x;
    offset.y = (thickness/2.f)*unitPerpendicular.y;

    vertices[0].position = point1 + offset;
    vertices[1].position = point1 - offset;
    vertices[2].position = point2 + offset;
    vertices[3].position = point2 - offset;

    for (int i=0; i<4; ++i)
        vertices[i].color = color;
}

void DrawableStroke::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(vertices,states);
}