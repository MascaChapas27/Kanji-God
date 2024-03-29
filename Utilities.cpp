#include "Utilities.hpp"
#include "ResourceHolder.hpp"

bool util::isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight)
{
    return  x > rectX &&
            x < rectX+rectWidth &&
            y > rectY &&
            y < rectY+rectHeight;
}

bool util::shouldLearnNewKanji(int practicingKanji)
{
    return practicingKanji == 0 || rand()%(practicingKanji*3) == 0;
}

sf::Sound util::initializeSound(SoundID soundId){
    sf::Sound sound;
    sound.setBuffer(SoundHolder::getSoundInstance()->get(soundId));
    return sound;
}