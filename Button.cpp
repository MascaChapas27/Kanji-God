#include "Button.hpp"
#include "Utilities.hpp"

Button::Button(){
    topOffset = util::MAX_BUTTON_TOP_OFFSET;
}

void Button::setBottomTexture(sf::Texture &texture)
{
    bottomSprite.setTexture(texture);
    bottomSprite.setOrigin(bottomSprite.getTextureRect().width/2,bottomSprite.getTextureRect().height/2);
}

void Button::setTopTexture(sf::Texture &texture)
{
    bottomSprite.setTexture(texture);
    bottomSprite.setOrigin(bottomSprite.getTextureRect().width/2,bottomSprite.getTextureRect().height/2);
}

void Button::setPosition(double x, double y)
{
    bottomSprite.setPosition(x,y);
    topSprite.setPosition(x,y-topOffset);
}

void Button::setPosition(sf::Vector2f position)
{
    setPosition(position.x,position.y);
}

void Button::update()
{
    double currentOffset = bottomSprite.getPosition().y - topSprite.getPosition().y;

    double newOffset = (currentOffset + topOffset) / 2.0;

    topSprite.setPosition(bottomSprite.getPosition().x, bottomSprite.getPosition().y-newOffset);
}

void Button::notify(sf::Event &event)
{
    if(event.type == sf::Event::EventType::MouseMoved){
        if(util::isInRectangle(event.mouseMove.x,event.mouseMove.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            topOffset = util::MID_BUTTON_TOP_OFFSET;
        }
    } else if (event)
}

        // Draws the button
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;