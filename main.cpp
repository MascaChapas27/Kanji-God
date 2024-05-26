#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Sign.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "MainWindow.hpp"
#include "KanjiRepository.hpp"
#include <ctime>
#include "DrawingBoard.hpp"

int main(){
    srand(time(NULL));

    sf::RenderWindow window;
    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);

    DrawingBoard board;
    board.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    board.setBoardTexture(TextureHolder::getTextureInstance()->get(TextureID::QuestionSign));

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS);
            } else {
                board.notify(event);
            }
        }

        window.clear();

        window.draw(board);

        window.display();

    }

    /*
    MainWindow mainWindow;
    
    mainWindow.start();
    */
}