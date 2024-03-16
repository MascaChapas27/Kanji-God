#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <SFML/Graphics.hpp>
#include <functional>

/*
    This class defines a button formed by a top part and a bottom
    part. The top part moves and the bottom part stays still to
    make it look like it has depth when you press it
*/
class Button : public sf::Drawable{
    private:
        // Sprite for the bottom part of the sprite (defines position and
        // doesn't move)
        sf::Sprite bottomSprite;

        // Sprite for the top part of the sprite (is on top of the position and)
        sf::Sprite topSprite;

        // Indicates how far the top part is from the bottom part. 0 means
        // they will be at the same Y position. 10 means the top part will be
        // 10 pixels on top of the bottom part
        double topOffset;

        // Indicates if the button is currently being pressed
        bool pressed;

        sf::Font font; // TODO get rid of this

        // Text to be displayed on the button
        sf::Text text;

        // Action to be performed when the button is pressed
        std::function<void(Button&)> pressedButtonAction;

        // Action to be performed when the button is released
        std::function<void(Button&)> releasedButtonAction;

    public:
        Button();

        // Sets the texture for the bottom part of the button
        void setBottomTexture(sf::Texture &texture);

        // Sets the texture for the top part of the button
        void setTopTexture(sf::Texture &texture);

        // Sets the current position for the bottom part. The top part will
        // follow it and position itself some pixels above depending on the offset
        void setPosition(double x, double y);
        void setPosition(sf::Vector2f position);

        // Sets the action to be performed when the button is pressed
        void setPressedButtonAction(std::function<void(Button&)> pressedButtonAction);

        // Sets the action to be performed when the button is released
        void setReleasedButtonAction(std::function<void(Button&)> releasedButtonAction);

        // Sets the text to be displayed on the button
        void setText(sf::String text, bool keepSize = false);

        // Returns the text
        std::wstring getText();

        // Sets the color for the text
        void setTextColor(sf::Color textColor);

        // Sets the color for the button
        void setButtonColor(sf::Color color);

        // Update the position of the top part of the button
        void update();

        // Reacts to an event that happened
        void notify(sf::Event &event);

        // Draws the button
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
