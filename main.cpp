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
    window->create(sf::VideoMode(1920,1080), "Gra RPG", sf::Style::Fullscreen);
    window->setActive(true);
    window->setPosition(sf::Vector2i(10, 10));
    sf::Event event;
    sf::Texture uiActive, uiDisabled, mainscr;
    if(!uiActive.loadFromFile("images/ui_active.png")) {
        #ifdef _DEBUG
        cout << "(\"images/ui_active.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    if(!uiDisabled.loadFromFile("images/ui_disabled.png")) {
        #ifdef _DEBUG
        cout << "(\"images/ui_disabled.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    if(!mainscr.loadFromFile("images/mainscreen.png")) {
        #ifdef _DEBUG
        cout << "(\"images/mainscreen.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    CMainScreen * mainScreen = new CMainScreen(window, &mainscr);
    while(window->isOpen()) {
        window->clear(sf::Color::White);
        switch(mainScreen->run()) {

        }
        window->display();
    }
    delete window, mainScreen;
    return 0;
}
