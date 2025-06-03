#include "Button.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "Enums.hpp"

sf::Sound Button::pressButtonSound = util::initializeSound(SoundID::PressButton);
sf::Sound Button::releaseButtonSound = util::initializeSound(SoundID::ReleaseButton);
sf::Sound Button::hoverOverButtonSound = util::initializeSound(SoundID::HoverOverButton);

Button::Button(const sf::Texture& bottomTexture, const sf::Texture& topTexture) : bottomSprite(bottomTexture), topSprite(topTexture), text(FontHolder::getInstance()->get(FontID::MoboFont)) {
    bottomSprite.setOrigin({bottomSprite.getTextureRect().size.x/2.f,bottomSprite.getTextureRect().size.y/2.f});
    topSprite.setOrigin({topSprite.getTextureRect().size.x/2.f,topSprite.getTextureRect().size.y/2.f});
    textButtonRatio = (topSprite.getTextureRect().size.x - BUTTON_TEXT_MARGIN) / topSprite.getTextureRect().size.x;

    topOffset = MAX_BUTTON_TOP_OFFSET;
    pressed = false;
    mouseInside = false;
    pressedButtonAction = [](Button &button){};
    releasedButtonAction = [](Button &button){};
}

void Button::setBottomTexture(const sf::Texture &texture)
{
    bottomSprite.setTexture(texture);
    bottomSprite.setOrigin({bottomSprite.getTextureRect().size.x/2.f,bottomSprite.getTextureRect().size.y/2.f});
}

void Button::setTopTexture(const sf::Texture &texture)
{
    topSprite.setTexture(texture);
    topSprite.setOrigin({topSprite.getTextureRect().size.x/2.f,topSprite.getTextureRect().size.y/2.f});
    textButtonRatio = (topSprite.getTextureRect().size.x - BUTTON_TEXT_MARGIN) / topSprite.getTextureRect().size.x;
}

void Button::setPosition(float x, float y)
{
    bottomSprite.setPosition({x,y});
    topSprite.setPosition({x,y-topOffset});
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
             (text.getGlobalBounds().size.x > topSprite.getTextureRect().size.x*textButtonRatio ||
              text.getGlobalBounds().size.y > topSprite.getTextureRect().size.y*textButtonRatio)){
            text.setCharacterSize(text.getCharacterSize()-1);
        }

        while(text.getGlobalBounds().size.x > topSprite.getTextureRect().size.x*textButtonRatio ||
              text.getGlobalBounds().size.y > topSprite.getTextureRect().size.y*textButtonRatio){

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
                    while(text.getGlobalBounds().size.x < topSprite.getTextureRect().size.x*textButtonRatio &&
                        text.getGlobalBounds().size.y < topSprite.getTextureRect().size.y*textButtonRatio){
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
    float currentOffset = bottomSprite.getPosition().y - topSprite.getPosition().y;

    float newOffset = currentOffset + (topOffset - currentOffset) / BUTTON_PRESS_SPEED;

    topSprite.setPosition({bottomSprite.getPosition().x, bottomSprite.getPosition().y-newOffset});
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
    topSprite.setPosition({bottomSprite.getPosition().x,bottomSprite.getPosition().y-topOffset});
}

void Button::notify(sf::Event &event)
{
    if(!pressed && event.is<sf::Event::MouseMoved>()){
        if(!mouseInside && util::isInRectangle(event.getIf<sf::Event::MouseMoved>()->position.x,event.getIf<sf::Event::MouseMoved>()->position.y,topSprite.getPosition().x-topSprite.getTextureRect().size.x/2.f,topSprite.getPosition().y-topSprite.getTextureRect().size.y/2.f,topSprite.getTextureRect().size.x,topSprite.getTextureRect().size.y)){
            // Hovering over the button
            hoverOverButtonSound.play();
            topOffset = MID_BUTTON_TOP_OFFSET;
            mouseInside = true;
        } else if(mouseInside && !util::isInRectangle(event.getIf<sf::Event::MouseMoved>()->position.x,event.getIf<sf::Event::MouseMoved>()->position.y,topSprite.getPosition().x-topSprite.getTextureRect().size.x/2.f,topSprite.getPosition().y-topSprite.getTextureRect().size.y/2.f,topSprite.getTextureRect().size.x,topSprite.getTextureRect().size.y)){
            // Mouse is out of the button
            topOffset = MAX_BUTTON_TOP_OFFSET;
            mouseInside = false;
        }
    } else if (!pressed && event.is<sf::Event::MouseButtonPressed>() && event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left){
        if(util::isInRectangle(event.getIf<sf::Event::MouseButtonPressed>()->position.x,event.getIf<sf::Event::MouseButtonPressed>()->position.y,topSprite.getPosition().x-topSprite.getTextureRect().size.x/2.f,topSprite.getPosition().y-topSprite.getTextureRect().size.y/2.f,topSprite.getTextureRect().size.x,topSprite.getTextureRect().size.y)){
            // Pressed on the button
            pressButtonSound.play();
            topSprite.setPosition(bottomSprite.getPosition());
            topOffset = MIN_BUTTON_TOP_OFFSET;
            pressed = true;
            pressedButtonAction(*this);
        }
    } else if (pressed && event.is<sf::Event::MouseButtonReleased>() && event.getIf<sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Left){

        releaseButtonSound.play();

        if(util::isInRectangle(event.getIf<sf::Event::MouseButtonReleased>()->position.x,event.getIf<sf::Event::MouseButtonReleased>()->position.y,topSprite.getPosition().x-topSprite.getTextureRect().size.x/2.f,topSprite.getPosition().y-topSprite.getTextureRect().size.y/2.f,topSprite.getTextureRect().size.x,topSprite.getTextureRect().size.y)){
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
    target.draw(bottomSprite,states);
    target.draw(topSprite,states);
    if(text.getString() != "") target.draw(text,states);
}
