#include "DrawingBoard.hpp"
#include <iostream>

DrawingBoard::DrawingBoard(){
    currentlyDrawing = false;
}

void DrawingBoard::setBoardTexture(sf::Texture &texture){
    boardSprite.setTexture(texture);
}

void DrawingBoard::setPosition(double x, double y){

    // Difference in position
    sf::Vector2f diff(x-boardSprite.getPosition().x,y-boardSprite.getPosition().y);

    boardSprite.setPosition(x,y);
    for(sf::VertexArray &va : strokes){
        for(int i=0;i<va.getVertexCount();i++){
            va[i].position.x += diff.x;
            va[i].position.y += diff.y;
        }
    }
}

void DrawingBoard::setPosition(sf::Vector2f position){
    setPosition(position.x,position.y);
}

void DrawingBoard::setBoardColor(sf::Color color){
    boardSprite.setColor(color);
}

void DrawingBoard::notify(sf::Event &event){

    if(!currentlyDrawing && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = true;
        sf::VertexArray va;
        va.setPrimitiveType(sf::LineStrip);

        sf::Vertex v(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
        v.color = sf::Color::Black;

        va.append(v);
        strokes.push_back(va);
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseMoved)
    {
        sf::VertexArray &va = strokes.back();
        sf::Vertex v(sf::Vector2f(event.mouseMove.x,event.mouseMove.y));
        v.color = sf::Color::Black;
        va.append(v);
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = false;
    }
}

void DrawingBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boardSprite,states);
    for(sf::VertexArray v : strokes){
        target.draw(v,states);
    }
}