#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Sign.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "MainWindow.hpp"
#include "KanjiRepository.hpp"
#include <ctime>

int main(){
    // Load all fonts
    FontHolder::getFontInstance()->loadAllFonts();

    // Load all textures
    TextureHolder::getTextureInstance()->loadAllTextures();

    // Load all sounds
    SoundHolder::getSoundInstance()->loadAllSounds();

    // Load all kanjis
    KanjiRepository::getInstance()->loadAllKanjis();

    srand(time(NULL));

    MainWindow mainWindow;
    
    mainWindow.start();
}