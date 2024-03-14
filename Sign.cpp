#include "Sign.hpp"
#include "Utilities.hpp"
#include "Enums.hpp"
#include "ResourceHolder.hpp"

Sign::Sign(){
    text.setFont(FontHolder::getFontInstance()->get(FontID::MoboFont));
}

void Sign::setSignTexture(sf::Texture &texture){
    signSprite.setTexture(texture);
    signSprite.setOrigin(signSprite.getTextureRect().width/2,signSprite.getTextureRect().height/2);
}

void Sign::setPosition(double x, double y){
    signSprite.setPosition(x,y);
}

void Sign::setPosition(sf::Vector2f position){
    this->setPosition(position.x, position.y);
}

void Sign::setText(sf::String textString){
    text.setString(textString);
    text.setCharacterSize(INITIAL_FONT_SIZE);

    while(text.getGlobalBounds().width > signSprite.getTextureRect().width*0.6){
        text.setCharacterSize(text.getCharacterSize()-1);
    }

    sf::Vector2f center(text.getGlobalBounds().width / 2.0, text.getGlobalBounds().height / 2.0);
    sf::Vector2f localBounds(center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top);
    text.setOrigin(localBounds);
    text.setPosition(signSprite.getPosition());
}

void Sign::setTextColor(sf::Color textColor){
    text.setFillColor(textColor);
}

void Sign::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(signSprite);
    target.draw(text);
}