#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "src/menu/CMainScreen.h"

using namespace std;

sf::RenderWindow * window;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(640,400), "Gra RPG");
    window->setActive(true);
    window->setPosition(sf::Vector2i(10, 10));
    sf::Event event;
    CMainScreen * mainScreen = new CMainScreen(window);
    while(window->isOpen()) {
        window->clear(sf::Color::White);
        if(mainScreen->run()) {

        }
        window->display();
    }
    delete window, mainScreen;
    return 0;
}
