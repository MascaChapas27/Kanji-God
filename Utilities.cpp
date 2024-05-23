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

bool util::shouldLearnNewContent(int practicingContent, bool isWord)
{
    // If there is no content to practice, then it's necessary to learn new content.
    // But if there is content being practiced, words have a higher change to be learnt
    return practicingContent == 0 || rand()%((isWord ? 0 : 5)+practicingContent) == 0;
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

hash_t util::hash(std::wstring wstring){
    hash_t hashCode = 0;

    // Depending on the position, the value will be multiplied by this multiplier
    hash_t multiplier = 1;

    for(wchar_t wchar : wstring){
        // The wchar_t type is 16 bits long so it can be used as a number
        hashCode+=(wchar*multiplier);

        // For the next iteration, the multiplier will be bigger
        multiplier+=10000;
    }

    return hashCode;
}
