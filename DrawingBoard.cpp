#include "DrawingBoard.hpp"
#include "Utilities.hpp"
#include <iostream>

DrawingBoard::DrawingBoard(){
    currentlyDrawing = false;
    captureCountMax = VERTEX_DELAY;
    captureCount = captureCountMax;
}

void DrawingBoard::setBoardTexture(sf::Texture &texture){
    boardSprite.setTexture(texture);
    boardSprite.setOrigin(boardSprite.getTextureRect().width/2,boardSprite.getTextureRect().height/2);
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

void DrawingBoard::clearBoard(){
    strokes.clear();
    currentlyDrawing = false;
    captureCount = captureCountMax;
}

void DrawingBoard::undo(){
    if(strokes.empty()) return;
    
    strokes.pop_back();
    currentlyDrawing = false;
    captureCount = captureCountMax;
}

void DrawingBoard::notify(sf::Event &event){

    if(!currentlyDrawing && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = true;
        captureCount = captureCountMax;
        sf::VertexArray va;
        va.setPrimitiveType(sf::LineStrip);

        strokes.push_back(va);

        captureVertex(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseMoved)
    {
        captureVertex(sf::Vector2f(event.mouseMove.x,event.mouseMove.y));
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = false;
    }
}

void DrawingBoard::dump(){
    for(sf::VertexArray &va : strokes){
        for(int i=0;i<va.getVertexCount();i++){
            std::cout << va[i].position.x-boardSprite.getPosition().x << "," << va[i].position.y-boardSprite.getPosition().y << ";";
        }
        std::cout << std::endl;
    }
}

void DrawingBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boardSprite,states);
    for(sf::VertexArray v : strokes){
        target.draw(v,states);
    }
}

void DrawingBoard::captureVertex(sf::Vector2f position){
    
    if(captureCount == captureCountMax){
        sf::Vertex v(position);
        v.color = sf::Color::Black;
        strokes.back().append(v);
        
        captureCount = 0;
    } else {
        captureCount++;
    }
}