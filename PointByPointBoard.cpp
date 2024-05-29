#include "PointByPointBoard.hpp"
#include "DrawableStroke.hpp"
#include "Utilities.hpp"
#include <iostream>

void PointByPointBoard::undo(){

    if(strokes.empty()) return;

    if(strokes.back().getVertexCount() > 1) strokes.back().resize(strokes.back().getVertexCount()-1);
    else strokes.pop_back();

    if(strokes.empty()){
        currentlyDrawing = false;
    }
}

void PointByPointBoard::notify(sf::Event &event){

    if(!currentlyDrawing && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = true;
        mousePosition.x = event.mouseButton.x;
        mousePosition.y = event.mouseButton.y;

        sf::VertexArray va;
        va.setPrimitiveType(sf::LineStrip);

        strokes.push_back(va);

        if(!captureVertex(sf::Vector2f(event.mouseButton.x,event.mouseButton.y))){
            strokes.pop_back();
            currentlyDrawing = false;
        }
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        if(!captureVertex(sf::Vector2f(event.mouseButton.x,event.mouseButton.y))){
            endStroke();
        }
    }
    else if (currentlyDrawing && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Right)
    {
        endStroke();
    } else if (currentlyDrawing && event.type == sf::Event::MouseMoved){
        mousePosition.x = event.mouseMove.x;
        mousePosition.y = event.mouseMove.y;
    }
}

void PointByPointBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boardSprite,states);
    unsigned int strokeCounter = 0;
    for(sf::VertexArray v : strokes){
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

        if(strokeCounter == strokes.size()-1 && currentlyDrawing){
            DrawableStroke d(strokes.back()[strokes.back().getVertexCount()-1].position,mousePosition,strokeColor,STROKE_THICKNESS);
            target.draw(d,states);
            sf::CircleShape c;
            c.setFillColor(strokeColor);
            c.setRadius(STROKE_THICKNESS/2);
            c.setOrigin(STROKE_THICKNESS/2,STROKE_THICKNESS/2);
            c.setPosition(mousePosition);
            target.draw(c,states);
        }

        strokeCounter++;
    }
}

bool PointByPointBoard::captureVertex(sf::Vector2f position){

    if(position.x > boardSprite.getPosition().x+boardSprite.getTextureRect().width/2 ||
       position.x < boardSprite.getPosition().x-boardSprite.getTextureRect().width/2 ||
       position.y > boardSprite.getPosition().y+boardSprite.getTextureRect().height/2 ||
       position.y < boardSprite.getPosition().y-boardSprite.getTextureRect().height/2) return false;


    sf::Vertex v(position);
    v.color = strokeColor;
    strokes.back().append(v);

    return true;
}
