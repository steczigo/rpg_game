#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "src/menu/CMainScreen.h"
#include "src/UI/CCursor.h"

using namespace std;

sf::RenderWindow * window;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    window = new sf::RenderWindow();
    #ifdef _RELEASE
        cout << "Run in release mode." << endl;
        vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
        window->create(modes.at(0), "Gra RPG", sf::Style::Fullscreen);
        modes.clear();
    #else
        cout << "Run in debug mode." << endl;
        window->create(sf::VideoMode(640, 400), "Gra RPG");
    #endif
    window->setActive(true);
    window->setFramerateLimit(60);
    sf::Event event;
    sf::Texture uiActive, uiDisabled, mainscr;
    if(!uiActive.loadFromFile("images/ui_active.png")) {
        #ifdef _DEBUG
        cout << "(\"images/ui_active.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    if(!uiDisabled.loadFromFile("images/ui_disable.png")) {
        #ifdef _DEBUG
        cout << "(\"images/ui_disabled.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    if(!mainscr.loadFromFile("images/mainscreen.png")) {
        #ifdef _DEBUG
        cout << "(\"images/mainscreen.png\") Loading resource failed!" << endl;
        #endif // _DEBUG
    }
    CCursor* mousePointer = new CCursor(window, uiActive);
    CMainScreen* mainScreen = new CMainScreen(window, &mainscr, &uiActive);
    while(window->isOpen()) {
        window->clear(sf::Color::White);
        switch(mainScreen->run()) {

        }
        mousePointer->run();
        window->display();
    }
    delete window, mainScreen, mousePointer;
    return 0;
}
