#include "Button.hpp"
#include "Utilities.hpp"
#include <iostream>

Button::Button(){
    topOffset = MAX_BUTTON_TOP_OFFSET;
    pressed = false;
}

void Button::setBottomTexture(sf::Texture &texture)
{
    bottomSprite.setTexture(texture);
    bottomSprite.setOrigin(bottomSprite.getTextureRect().width/2,bottomSprite.getTextureRect().height/2);
}

void Button::setTopTexture(sf::Texture &texture)
{
    topSprite.setTexture(texture);
    topSprite.setOrigin(bottomSprite.getTextureRect().width/2,bottomSprite.getTextureRect().height/2);
}

void Button::setPosition(double x, double y)
{
    bottomSprite.setPosition(x,y);
    topSprite.setPosition(x,y-topOffset);
}

void Button::setPosition(sf::Vector2f position)
{
    this->setPosition(position.x,position.y);
}

void Button::setText(sf::String textString)
{
    if(!font.loadFromFile("fonts/MOBO-Bold.otf"))
    {
        exit(EXIT_FAILURE);
    }

    text.setFont(font);

    text.setString(textString);
    text.setCharacterSize(INITIAL_FONT_SIZE);

    while(text.getGlobalBounds().getSize().x > topSprite.getTextureRect().width*0.6){
        text.setCharacterSize(text.getCharacterSize()-1);
    }

    sf::Vector2f center(text.getGlobalBounds().getSize().x / 2.0, text.getGlobalBounds().getSize().y / 2.0);
    sf::Vector2f localBounds(center.x + text.getLocalBounds().getPosition().x, center.y + text.getLocalBounds().getPosition().y);
    text.setOrigin(localBounds);
    text.setPosition(topSprite.getPosition());

    text.setFillColor(sf::Color(122,122,122));
}

void Button::update()
{
    double currentOffset = bottomSprite.getPosition().y - topSprite.getPosition().y;

    double newOffset = currentOffset + (topOffset - currentOffset) / BUTTON_PRESS_SPEED;

    topSprite.setPosition(bottomSprite.getPosition().x, bottomSprite.getPosition().y-newOffset);
    text.setPosition(topSprite.getPosition());
}

void Button::notify(sf::Event &event)
{
    if(!pressed && event.type == sf::Event::EventType::MouseMoved){
        if(util::isInRectangle(event.mouseMove.x,event.mouseMove.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            topOffset = MID_BUTTON_TOP_OFFSET;
        } else {
            topOffset = MAX_BUTTON_TOP_OFFSET;
        }
    } else if (!pressed && event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left){
        if(util::isInRectangle(event.mouseButton.x,event.mouseButton.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            topSprite.setPosition(bottomSprite.getPosition());
            topOffset = MIN_BUTTON_TOP_OFFSET;
            pressed = true;
        }
    } else if (pressed && event.type == sf::Event::EventType::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left){
        
        if(util::isInRectangle(event.mouseButton.x,event.mouseButton.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            topOffset = MID_BUTTON_TOP_OFFSET;
        } else {
            topOffset = MAX_BUTTON_TOP_OFFSET;
        }
        
        pressed = false;
    }
}

// Draws the button
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bottomSprite);
    target.draw(topSprite);
    if(text.getString() != "") target.draw(text);
}