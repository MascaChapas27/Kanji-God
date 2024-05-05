#include <SFML/System.hpp>

#include "Utilities.hpp"
#include "ResourceHolder.hpp"

bool util::isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight)
{
    return  x > rectX &&
            x < rectX+rectWidth &&
            y > rectY &&
            y < rectY+rectHeight;
}

bool util::shouldLearnNewContent(int practicingContent)
{
    return practicingContent == 0 || rand()%(practicingContent*4) == 0;
}

sf::Sound util::initializeSound(SoundID soundId){
    sf::Sound sound;
    sound.setBuffer(SoundHolder::getSoundInstance()->get(soundId));
    return sound;
}

std::wstring util::trimLineFeeds(std::wstring answer){
    std::size_t position;
    while((position = answer.find(L"\n")) != std::string::npos)
        answer.replace(position,1,L" ");
    return answer;
}
