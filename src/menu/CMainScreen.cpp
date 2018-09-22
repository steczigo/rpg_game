#include "CMainScreen.h"

/***********************************************
* \brief Main constructor of CMainScreen class.
*
* \param sf::Window *window pointer
* \return none
*
***********************************************/
CMainScreen::CMainScreen(sf::RenderWindow *window) {
    this->window = window;
    this->przycisk = new CButton(window);
}

int CMainScreen::run() {
    this->przycisk->setRect(sf::IntRect(50, 10, 150, 30));
    sf::Event event;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
    }
    przycisk->stateProvider();
    window->draw(*przycisk);
}
