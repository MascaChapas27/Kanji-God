#ifndef __SIGN_HPP__
#define __SIGN_HPP__

#include <SFML/Graphics.hpp>

/*
    This class defines a sign formed by a bottom part and text
    on top (it can't be clicked)
*/
class Sign : public sf::Drawable{
    private:
        // Sprite for the sign
        sf::Sprite signSprite;

        // Text to be displayed on the sign
        sf::Text text;

        // How big the text can get compared to the size of the sign
        float textSignRatio;

        // Maximum size for the text (if it doesn't fit, it will be smaller)
        int maxTextSize;

    public:

        // Constructor for the sign using its texture
        Sign(const sf::Texture& texture);

        // Sets the texture for the sign
        void setSignTexture(const sf::Texture &texture);

        // Sets the current position for the sign
        void setPosition(float x, float y);
        void setPosition(sf::Vector2f position);

        // Sets the text to be displayed on the sign
        void setText(sf::String textString, bool keepSize = false);

        // Sets the color for the text
        void setTextColor(sf::Color textColor);

        // Sets the color for the sign
        void setSignColor(sf::Color color);

        // Get the text that the sign contains
        sf::String getText();

        // Sets the font for the text
        void setFont(sf::Font &font);

        // Sets the maximum size for the text
        void setMaxTextSize(int size);

        // Draws the button
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
