#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Sign.hpp"
#include "Utilities.hpp"
#include "ResourceHolder.hpp"
#include "MainWindow.hpp"
#include "KanjiRepository.hpp"
#include <ctime>
#include "PointByPointBoard.hpp"
#include <optional>

// This debug function allows you to create your own strokes
// and dump them as vertex coordinates (implementation is under the main function)
void debugStroke();

int main(){
    srand(time(NULL));

    //debugStroke();

    MainWindow mainWindow;

    mainWindow.start();
}

// This debug function allows you to create your own strokes
// and dump them as vertex coordinates
void debugStroke(){
    sf::RenderWindow window;
    window.create(sf::VideoMode({WINDOW_WIDTH/2,WINDOW_HEIGHT/2}),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);

    PointByPointBoard board(TextureHolder::getInstance()->get(TextureID::DrawingBoard));
    board.setPosition({WINDOW_WIDTH/4,WINDOW_HEIGHT/4});
    board.setBoardColor(BOARD_TUTORIAL_SHOW_COLOR);
    board.setStrokeColor(STROKE_TUTORIAL_SHOW_COLOR);

    while(window.isOpen()){

        std::optional<sf::Event> event;
        while(event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
                exit(EXIT_SUCCESS);
            } else if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scancode::Enter){
                board.dump();
            } else if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scancode::Backspace){
                board.clearBoard();
            } else if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scancode::Space){
                board.undo();
            } else if (event.has_value()){
                board.notify(event.value());
            }
        }

        window.clear(sf::Color(100,100,100));

        window.draw(board);

        window.display();
    }

    exit(EXIT_SUCCESS);
}
