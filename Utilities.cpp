#include "Utilities.hpp"

namespace util{
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight)
    {
        return  event.mouseMove.x > topSprite.getPosition().x &&
                event.mouseMove.x < topSprite.getPosition().x+topSprite.getTextureRect().width &&
                event.mouseMove.y > topSprite.getPosition().y &&
                event.mouseMove.y < topSprite.getPosition().y+topSprite.getTextureRect().height;
    }
}