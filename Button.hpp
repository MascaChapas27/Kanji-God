#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <SFML/Graphics.hpp>

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

        // Update the position of the top part of the button
        void update();

        // Reacts to an event that happened
        void notify(sf::Event &event);

        // Draws the button
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif