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
    srand(time(NULL));

    MainWindow mainWindow;
    
    mainWindow.start();
}