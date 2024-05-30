#include "ShowingBoard.hpp"
#include "Utilities.hpp"
#include "DrawableStroke.hpp"
#include <iostream>

ShowingBoard::ShowingBoard(){
    strokeColor = sf::Color::Black;
    finishedStrokeAction = [](DrawingBoard &drawingBoard){};
    currentStroke = 0;
}

void ShowingBoard::notify(sf::Event &event){
    // Nothing to do here
}

void ShowingBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boardSprite,states);
    int strokeCounter = 0;
    for(sf::VertexArray v : strokes){

        if(strokeCounter > currentStroke) break;

        if(strokeCounter == currentStroke){
            sf::CircleShape c;
            c.setFillColor(FIRST_VERTEX_COLOR);
            c.setRadius(FIRST_VERTEX_RADIUS);
            c.setOrigin(FIRST_VERTEX_RADIUS,FIRST_VERTEX_RADIUS);
            c.setPosition(v[0].position);
            target.draw(c,states);
        }
        for(unsigned int i=0;i<v.getVertexCount()-1;i++){
            DrawableStroke d(v[i].position,v[i+1].position,strokeColor,STROKE_THICKNESS);
            target.draw(d,states);
            sf::CircleShape c;
            c.setFillColor(strokeColor);
            c.setRadius(STROKE_THICKNESS/2);
            c.setOrigin(STROKE_THICKNESS/2,STROKE_THICKNESS/2);
            c.setPosition(v[i].position);
            target.draw(c,states);
        }
        sf::CircleShape c;
        c.setFillColor(strokeColor);
        c.setRadius(STROKE_THICKNESS/2);
        c.setOrigin(STROKE_THICKNESS/2,STROKE_THICKNESS/2);
        c.setPosition(v[v.getVertexCount()-1].position);
        target.draw(c,states);

        strokeCounter++;
    }
}

void ShowingBoard::undo(){
    if(currentStroke != 0) currentStroke--;
}

void ShowingBoard::nextStroke(){
    currentStroke++;
}

void ShowingBoard::setStrokes(std::vector<sf::VertexArray> strokes){

    for(sf::VertexArray &va : strokes){
        for(size_t i = 0;i<va.getVertexCount();i++){
            va[i].position.x += boardSprite.getPosition().x;
            va[i].position.y += boardSprite.getPosition().y;
        }
    }

    this->strokes = strokes;

    currentStroke = 0;
}