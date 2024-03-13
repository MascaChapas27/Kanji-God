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

    Button button;
    button.setBottomTexture(bottomTexture);
    button.setTopTexture(topTexture);
    button.setPosition(200,150);
    button.setText(L"あ");

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
        window.display();
    }
    
}