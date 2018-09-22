#include "CMainScreen.h"

/***********************************************
* \brief Main constructor of CMainScreen class.
*
* \param pointer to rendered window
* \return none
*
***********************************************/
CMainScreen::CMainScreen(sf::RenderWindow *window, sf::Texture* tx) {
    this->window = window;
    this->backgroundTexture = tx;
    this->przycisk = new CButton(window);
}

int CMainScreen::run() {
    this->przycisk->setRect(sf::IntRect(50, 10, 150, 30));
    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    //this->background->setScale(1.2, 1.2);
    sf::Event event;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
    }
    przycisk->stateProvider();
    window->draw(*background);
    window->draw(*przycisk);
}
