#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Utilities.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(400,300),"amai",sf::Style::Close);
    window.setFramerateLimit(FPS);

    sf::Texture bottomTexture;
    bottomTexture.loadFromFile("sprites/button_bottom.png");

    sf::Texture topTexture;
    topTexture.loadFromFile("sprites/button_top.png");

    Button button1;
    button1.setBottomTexture(bottomTexture);
    button1.setTopTexture(topTexture);
    button1.setPosition(125,150);
    button1.setText(L"あ");
    button1.setTextColor(FONT_COLOR);

    Button button2;
    button2.setBottomTexture(bottomTexture);
    button2.setTopTexture(topTexture);
    button2.setPosition(275,150);
    button2.setText(L"Me pican\nlos CoCo\naaaAY");
    button2.setTextColor(FONT_COLOR);

    while(window.isOpen()){
        
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS);
            } else {
                button1.notify(event);
                button2.notify(event);
            }
        }

        button1.update();
        button2.update();

        window.clear();
        window.draw(button1);
        window.draw(button2);
        window.display();
    }
    
}