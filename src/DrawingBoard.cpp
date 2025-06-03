#include "DrawingBoard.hpp"
#include "Utilities.hpp"
#include "DrawableStroke.hpp"
#include <iostream>

DrawingBoard::DrawingBoard(const sf::Texture& texture) : boardSprite(texture){
    currentlyDrawing = false;
    captureCountMax = VERTEX_DELAY;
    captureCount = captureCountMax;
    strokeColor = sf::Color::Black;
    finishedStrokeAction = [](DrawingBoard &drawingBoard){};
    boardSprite.setTexture(texture);
    boardSprite.setOrigin({boardSprite.getTextureRect().size.x/2.f,boardSprite.getTextureRect().size.y/2.f});
}

void DrawingBoard::setBoardTexture(sf::Texture& texture){
    boardSprite.setTexture(texture);
    boardSprite.setOrigin({boardSprite.getTextureRect().size.x/2.f,boardSprite.getTextureRect().size.y/2.f});
}

void DrawingBoard::setPosition(float x, float y){

    // Difference in position
    sf::Vector2f diff(x-boardSprite.getPosition().x,y-boardSprite.getPosition().y);

    boardSprite.setPosition({x,y});
    for(sf::VertexArray &va : strokes){
        for(unsigned int i=0;i<va.getVertexCount();i++){
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

void DrawingBoard::setStrokeColor(sf::Color color){
    strokeColor = color;
    for(sf::VertexArray &va : strokes){
        for(unsigned int i=0;i<va.getVertexCount();i++){
            va[i].color = color;
        }
    }
}

void DrawingBoard::setFinishedStrokeAction(std::function<void(DrawingBoard&)> finishedStrokeAction){
    this->finishedStrokeAction = finishedStrokeAction;
}

void DrawingBoard::addStroke(sf::VertexArray stroke){

    for(unsigned int i=0;i<stroke.getVertexCount();i++){
        stroke[i].position.x+=boardSprite.getPosition().x;
        stroke[i].position.y+=boardSprite.getPosition().y;
        stroke[i].color = strokeColor;
    }

    strokes.push_back(stroke);
}

sf::VertexArray DrawingBoard::getLatestStroke(){
    if(strokes.empty()) return sf::VertexArray();

    sf::VertexArray latestStroke = strokes.back();

    for(unsigned int i=0;i<latestStroke.getVertexCount();i++){
        latestStroke[i].position.x-=boardSprite.getPosition().x;
        latestStroke[i].position.y-=boardSprite.getPosition().y;
    }

    return latestStroke;
}

unsigned int DrawingBoard::getNumStrokes(){
    return strokes.size();
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

    if(!currentlyDrawing && event.is<sf::Event::MouseButtonPressed>() && event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left)
    {
        currentlyDrawing = true;
        captureCount = captureCountMax;
        sf::VertexArray va;
        va.setPrimitiveType(sf::PrimitiveType::LineStrip);

        strokes.push_back(va);

        if(!captureVertex(static_cast<sf::Vector2f>(event.getIf<sf::Event::MouseButtonPressed>()->position))){
            strokes.pop_back();
            currentlyDrawing = false;
        }
    }
    else if (currentlyDrawing && event.is<sf::Event::MouseMoved>())
    {
        if(!captureVertex(static_cast<sf::Vector2f>(event.getIf<sf::Event::MouseMoved>()->position))){
            endStroke();
        }
    }
    else if (currentlyDrawing && event.is<sf::Event::MouseButtonReleased>() && event.getIf<sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Left)
    {
        endStroke();
    }
}

void DrawingBoard::dump(){
    for(sf::VertexArray &va : strokes){
        for(unsigned int i=0;i<va.getVertexCount();i++){
            std::cout << va[i].position.x-boardSprite.getPosition().x << "," << va[i].position.y-boardSprite.getPosition().y << ";";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void DrawingBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boardSprite,states);
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
    }
}

bool DrawingBoard::captureVertex(sf::Vector2f position){

    if(position.x > boardSprite.getPosition().x+boardSprite.getTextureRect().size.x/2.f ||
       position.x < boardSprite.getPosition().x-boardSprite.getTextureRect().size.x/2.f ||
       position.y > boardSprite.getPosition().y+boardSprite.getTextureRect().size.y/2.f ||
       position.y < boardSprite.getPosition().y-boardSprite.getTextureRect().size.y/2.f) return false;


    if(captureCount == captureCountMax && (strokes.back().getVertexCount() == 0 || position != strokes.back()[strokes.back().getVertexCount()-1].position)){
        sf::Vertex v(position);
        v.color = strokeColor;
        strokes.back().append(v);

        captureCount = 0;
    } else {
        captureCount++;
    }

    return true;
}

void DrawingBoard::endStroke(){
    currentlyDrawing = false;
    finishedStrokeAction(*this);
}
