#include "PointByPointBoard.hpp"
#include "DrawableStroke.hpp"
#include "Utilities.hpp"
#include <iostream>

PointByPointBoard::PointByPointBoard(const sf::Texture& texture) :
    DrawingBoard(texture)
{

}

void PointByPointBoard::undo(){

    if(strokes.empty()) return;

    if(strokes.back().getVertexCount() > 1) strokes.back().resize(strokes.back().getVertexCount()-1);
    else strokes.pop_back();

    if(strokes.empty()){
        currentlyDrawing = false;
    }
}

void PointByPointBoard::notify(sf::Event &event){

    if(!currentlyDrawing && event.is<sf::Event::MouseButtonPressed>() && event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = true;
        mousePosition.x = event.getIf<sf::Event::MouseButtonPressed>()->position.x;
        mousePosition.y = event.getIf<sf::Event::MouseButtonPressed>()->position.y;

        sf::VertexArray va;
        va.setPrimitiveType(sf::PrimitiveType::LineStrip);

        strokes.push_back(va);

        if(!captureVertex({mousePosition.x,mousePosition.y})){
            strokes.pop_back();
            currentlyDrawing = false;
        }
    }
    else if (currentlyDrawing && event.is<sf::Event::MouseButtonPressed>() && event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left)
    {
        if(!captureVertex(static_cast<sf::Vector2f>(event.getIf<sf::Event::MouseButtonPressed>()->position))){
            endStroke();
        }
    }
    else if (currentlyDrawing && event.is<sf::Event::MouseButtonPressed>() && event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Right)
    {
        endStroke();
    }
    else if (currentlyDrawing && event.is<sf::Event::MouseMoved>())
    {
        mousePosition.x = event.getIf<sf::Event::MouseMoved>()->position.x;
        mousePosition.y = event.getIf<sf::Event::MouseMoved>()->position.y;
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
            c.setOrigin({STROKE_THICKNESS/2,STROKE_THICKNESS/2});
            c.setPosition(v[i].position);
            target.draw(c,states);
        }
        sf::CircleShape c;
        c.setFillColor(strokeColor);
        c.setRadius(STROKE_THICKNESS/2);
        c.setOrigin({STROKE_THICKNESS/2,STROKE_THICKNESS/2});
        c.setPosition(v[v.getVertexCount()-1].position);
        target.draw(c,states);

        if(strokeCounter == strokes.size()-1 && currentlyDrawing){
            DrawableStroke d(strokes.back()[strokes.back().getVertexCount()-1].position,mousePosition,strokeColor,STROKE_THICKNESS);
            target.draw(d,states);
            sf::CircleShape c;
            c.setFillColor(strokeColor);
            c.setRadius(STROKE_THICKNESS/2);
            c.setOrigin({STROKE_THICKNESS/2,STROKE_THICKNESS/2});
            c.setPosition(mousePosition);
            target.draw(c,states);
        }

        strokeCounter++;
    }
}

bool PointByPointBoard::captureVertex(sf::Vector2f position){

    if(position.x > boardSprite.getPosition().x+boardSprite.getTextureRect().size.x/2.f ||
       position.x < boardSprite.getPosition().x-boardSprite.getTextureRect().size.x/2.f ||
       position.y > boardSprite.getPosition().y+boardSprite.getTextureRect().size.y/2.f ||
       position.y < boardSprite.getPosition().y-boardSprite.getTextureRect().size.y/2.f) return false;


    sf::Vertex v(position);
    v.color = strokeColor;
    strokes.back().append(v);

    return true;
}
