#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Sign.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "MainWindow.hpp"

int main(){

    // Load all fonts
    FontHolder::getFontInstance()->loadAllFonts();

    // Load all textures
    TextureHolder::getTextureInstance()->loadAllTextures();

    // Load all sounds
    SoundHolder::getSoundInstance()->loadAllSounds();

    MainWindow mainWindow;
    
    mainWindow.start();

    /*
    sf::Texture bottomTexture;
    bottomTexture.loadFromFile("sprites/button_bottom.png");

    sf::Texture topTexture;
    topTexture.loadFromFile("sprites/button_top.png");

    Button button;
    button.setBottomTexture(bottomTexture);
    button.setTopTexture(topTexture);
    button.setPosition(125,150);
    button.setText(L"あ");
    button.setTextColor(FONT_COLOR);
    button.setPressedButtonAction([&button](){
        button.setText(L"amai");
    });
    button.setReleasedButtonAction([&button](){
        button.setText(L"あ");
    });

    Sign sign;
    sign.setSignTexture(topTexture);
    sign.setPosition(275,150);
    sign.setText(L"Me pican\nlos CoCo\naaaAY");
    sign.setTextColor(FONT_COLOR);

    while(window.isOpen()){
        
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS);
            } else {
                button.notify(event);
            }
        }

        button.update();

        window.clear();
        window.draw(button);
        window.draw(sign);
        window.display();
    }
    */
}