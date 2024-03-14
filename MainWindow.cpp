#include "MainWindow.hpp"
#include "ResourceHolder.hpp"

void MainWindow::start(){

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);
    
    background.setTexture(TextureHolder::getTextureInstance()->get(TextureID::Background));
    background.setScale(2.0, 2.0);
    title.setTexture(TextureHolder::getTextureInstance()->get(TextureID::Title));

    title.setPosition(TITLE_X, TITLE_Y);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS); 
            }
        }

        window.clear();

        window.draw(background);
        window.draw(title);

        window.display();
    }

}