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

        sf::Font font; // TODO get rid of this

        // Text to be displayed on the sign
        sf::Text text;
    
    public:

        Sign();
        
        // Sets the texture for the sign
        void setSignTexture(sf::Texture &texture);

        // Sets the current position for the sign
        void setPosition(double x, double y);
        void setPosition(sf::Vector2f position);

        // Sets the text to be displayed on the sign
        void setText(sf::String textString, bool keepSize = false);

        // Sets the color for the text
        void setTextColor(sf::Color textColor);

        // Sets the color for the sign
        void setSignColor(sf::Color color);

        // Draws the button
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif