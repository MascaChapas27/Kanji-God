#include "Button.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "Enums.hpp"

sf::Sound Button::pressButtonSound = util::initializeSound(SoundID::PressButton);
sf::Sound Button::releaseButtonSound = util::initializeSound(SoundID::ReleaseButton);
sf::Sound Button::hoverOverButtonSound = util::initializeSound(SoundID::HoverOverButton);

Button::Button(){
    text.setFont(FontHolder::getFontInstance()->get(FontID::MoboFont));
    topOffset = MAX_BUTTON_TOP_OFFSET;
    pressed = false;
    mouseInside = false;
    pressedButtonAction = [](Button &button){};
    releasedButtonAction = [](Button &button){};
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
    textButtonRatio = (topSprite.getTextureRect().width - BUTTON_TEXT_MARGIN) / topSprite.getTextureRect().width;
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

void Button::setPressedButtonAction(std::function<void(Button&)> pressedButtonAction){
    this->pressedButtonAction = pressedButtonAction;
}

void Button::setReleasedButtonAction(std::function<void(Button&)> releasedButtonAction){
    this->releasedButtonAction = releasedButtonAction;
}

void Button::setText(sf::String textString, bool keepSize)
{
    text.setString(textString);
    if(!keepSize){
        text.setCharacterSize(INITIAL_FONT_SIZE);

        while(text.getCharacterSize() > MIN_FONT_SIZE &&
             (text.getGlobalBounds().width > topSprite.getTextureRect().width*textButtonRatio ||
              text.getGlobalBounds().height > topSprite.getTextureRect().height*textButtonRatio)){
            text.setCharacterSize(text.getCharacterSize()-1);
        }

        while(text.getGlobalBounds().width > topSprite.getTextureRect().width*textButtonRatio ||
              text.getGlobalBounds().height > topSprite.getTextureRect().height*textButtonRatio){

            // This shit is too big let's try to find a space in the middle
            int spaces = 0;
            for(std::size_t i=0;i<textString.getSize();i++){
                if(textString[i]==' ') spaces++;
            }

            std::size_t spacePosition = textString.find(" ");
            for(int i=0;i<spaces/2;i++){
                spacePosition = textString.find(" ",spacePosition+1);
            }
            if(spacePosition != sf::String::InvalidPos){
                textString.replace(spacePosition,1,"\n");
                text.setString(textString);
                bool madeBigger = false;
                while(text.getGlobalBounds().width < topSprite.getTextureRect().width*textButtonRatio &&
                      text.getGlobalBounds().height < topSprite.getTextureRect().height*textButtonRatio){
                    text.setCharacterSize(text.getCharacterSize()+1);
                    madeBigger = true;
                }
                if(madeBigger){
                    text.setCharacterSize(text.getCharacterSize()-1);
                }
            }
        }
    }

    sf::Vector2f center(text.getGlobalBounds().width / 2.0, text.getGlobalBounds().height / 2.0);
    sf::Vector2f localBounds(center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top);
    text.setOrigin(localBounds);
    text.setPosition(topSprite.getPosition());
}

std::wstring Button::getText(){
    return text.getString().toWideString();
}

void Button::setTextColor(sf::Color textColor)
{
    text.setFillColor(textColor);
}

void Button::setButtonColor(sf::Color color)
{
    topSprite.setColor(color);
    bottomSprite.setColor(color);
    setFinalColor(color);
}

void Button::setFinalColor(sf::Color finalColor)
{
    this->finalColor = finalColor;
}

void Button::update()
{
    double currentOffset = bottomSprite.getPosition().y - topSprite.getPosition().y;

    double newOffset = currentOffset + (topOffset - currentOffset) / BUTTON_PRESS_SPEED;

    topSprite.setPosition(bottomSprite.getPosition().x, bottomSprite.getPosition().y-newOffset);
    text.setPosition(topSprite.getPosition());

    sf::Color currentColor = topSprite.getColor();

    if(currentColor != finalColor){
        currentColor.r += (finalColor.r - currentColor.r) / 10;
        currentColor.g += (finalColor.g - currentColor.g) / 10;
        currentColor.b += (finalColor.b - currentColor.b) / 10;
        currentColor.a += (finalColor.a - currentColor.a) / 10;
        topSprite.setColor(currentColor);
        bottomSprite.setColor(currentColor);
    }
}

void Button::resetPosition(){
    topOffset = MAX_BUTTON_TOP_OFFSET;
    topSprite.setPosition(bottomSprite.getPosition().x,bottomSprite.getPosition().y-topOffset);
}

void Button::notify(sf::Event &event)
{
    if(!pressed && event.type == sf::Event::MouseMoved){
        if(!mouseInside && util::isInRectangle(event.mouseMove.x,event.mouseMove.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            // Hovering over the button
            hoverOverButtonSound.play();
            topOffset = MID_BUTTON_TOP_OFFSET;
            mouseInside = true;
        } else if(mouseInside && !util::isInRectangle(event.mouseMove.x,event.mouseMove.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            // Mouse is out of the button
            topOffset = MAX_BUTTON_TOP_OFFSET;
            mouseInside = false;
        }
    } else if (!pressed && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(util::isInRectangle(event.mouseButton.x,event.mouseButton.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            // Pressed on the button
            pressButtonSound.play();
            topSprite.setPosition(bottomSprite.getPosition());
            topOffset = MIN_BUTTON_TOP_OFFSET;
            pressed = true;
            pressedButtonAction(*this);
        }
    } else if (pressed && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){

        releaseButtonSound.play();

        if(util::isInRectangle(event.mouseButton.x,event.mouseButton.y,topSprite.getPosition().x-topSprite.getTextureRect().width/2,topSprite.getPosition().y-topSprite.getTextureRect().height/2,topSprite.getTextureRect().width,topSprite.getTextureRect().height)){
            // Released and the mouse is in the button
            topOffset = MID_BUTTON_TOP_OFFSET;
        } else {
            // Released and the mouse is out of the button
            topOffset = MAX_BUTTON_TOP_OFFSET;
        }

        pressed = false;
        releasedButtonAction(*this);
    }
}

// Draws the button
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bottomSprite);
    target.draw(topSprite);
    if(text.getString() != "") target.draw(text);
}
