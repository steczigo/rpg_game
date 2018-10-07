#include "CMainScreen.h"
#include <iostream>

/***********************************************
* \brief Constructor
*
* \param pointer to rendered window
* \param pointer to texture which will display on screen
* \return none
*
***********************************************/
CMainScreen::CMainScreen(sf::RenderWindow *window, sf::Texture* tx) {
    this->window = window;
    this->backgroundTexture = tx;
    this->przycisk = new CButton(window);
    sf::Texture uiActive;
    if(!uiActive.loadFromFile("images/ui_active.png")) {
        #ifdef _DEBUG
        std::cout << "(\"images/ui_active.png\") Loading resource failed!" << std::endl;
        #endif // _DEBUG
    }
    this->przycisk->loadGUIFile(&uiActive);
}

/********************************************//**
 * \brief Displays components on window
 * \return void
 *
 ***********************************************/
int CMainScreen::run() {
    this->przycisk->setRect(sf::Vector2i(50, 10), sf::Vector2i(284, 55));
    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    //this->background->setScale(1.2, 1.2);
    sf::Event event;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || (event.type == sf::Event::Closed)) window->close();
    }
    przycisk->stateProvider();
    window->draw(*background);
    window->draw(*przycisk);
}
