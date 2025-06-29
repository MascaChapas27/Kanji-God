#include "Sign.hpp"
#include "Utilities.hpp"
#include "Enums.hpp"
#include "ResourceHolder.hpp"

Sign::Sign(const sf::Texture& texture) : signSprite(texture), text(FontHolder::getInstance()->get(FontID::MoboFont))
{
    maxTextSize = INITIAL_FONT_SIZE;

    signSprite.setOrigin({signSprite.getTextureRect().size.x/2.f,signSprite.getTextureRect().size.y/2.f});
    textSignRatio = (signSprite.getTextureRect().size.x - BUTTON_TEXT_MARGIN) / signSprite.getTextureRect().size.x;
}

void Sign::setSignTexture(const sf::Texture &texture)
{
    signSprite.setTexture(texture);
    signSprite.setOrigin({signSprite.getTextureRect().size.x/2.f,signSprite.getTextureRect().size.y/2.f});
    textSignRatio = (signSprite.getTextureRect().size.x - BUTTON_TEXT_MARGIN) / signSprite.getTextureRect().size.x;
}

void Sign::setPosition(float x, float y)
{
    signSprite.setPosition({x,y});
}

void Sign::setPosition(sf::Vector2f position)
{
    this->setPosition(position.x, position.y);
}

void Sign::setText(sf::String textString, bool keepSize)
{

    text.setString(textString);
    if(!keepSize){
        text.setCharacterSize(maxTextSize);

        while(text.getCharacterSize() > MIN_FONT_SIZE &&
             (text.getGlobalBounds().size.x > signSprite.getTextureRect().size.x*textSignRatio ||
              text.getGlobalBounds().size.y > signSprite.getTextureRect().size.y*textSignRatio)){
            text.setCharacterSize(text.getCharacterSize()-1);
        }

        while(text.getGlobalBounds().size.x > signSprite.getTextureRect().size.x*textSignRatio ||
              text.getGlobalBounds().size.y > signSprite.getTextureRect().size.y*textSignRatio){

            // This thing is too big, so let's try to find a space in the middle
            int spaces = 0;
            for(std::size_t i=0;i<textString.getSize();i++){
                if(textString[i]==' ') spaces++;
            }

            if(spaces == 0){
                // If there is no way to make it fit, let's make it even smaller
                // than the minimum size
                text.setCharacterSize(text.getCharacterSize()-1);
            } else {
                std::size_t spacePosition = textString.find(" ");
                for(int i=0;i<spaces/2;i++){
                    spacePosition = textString.find(" ",spacePosition+1);
                }
                if(spacePosition != sf::String::InvalidPos){
                    textString.replace(spacePosition,1,"\n");
                    text.setString(textString);
                    bool madeBigger = false;
                    while(text.getGlobalBounds().size.x < signSprite.getTextureRect().size.x*textSignRatio &&
                        text.getGlobalBounds().size.y < signSprite.getTextureRect().size.y*textSignRatio){
                        text.setCharacterSize(text.getCharacterSize()+1);
                        madeBigger = true;
                    }
                    if(madeBigger){
                        text.setCharacterSize(text.getCharacterSize()-1);
                    }
                }
            }
        }
    }

    sf::Vector2f center(text.getGlobalBounds().size.x / 2.0, text.getGlobalBounds().size.y / 2.0);
    sf::Vector2f localBounds(center.x + text.getLocalBounds().position.x, center.y + text.getLocalBounds().position.y);
    text.setOrigin(localBounds);
    text.setPosition(signSprite.getPosition());
}

void Sign::setTextColor(sf::Color textColor){
    text.setFillColor(textColor);
}

void Sign::setSignColor(sf::Color color){
    signSprite.setColor(color);
}

sf::String Sign::getText(){
    return text.getString().toWideString();
}

void Sign::setFont(sf::Font &font){
    text.setFont(font);
}

void Sign::setMaxTextSize(int size){
    maxTextSize = size;
}

void Sign::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(signSprite,states);
    target.draw(text,states);
}
