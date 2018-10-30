#include "CMainScreen.h"
#include "../UI/textureRect.h"
#include <iostream>

/***********************************************
* \brief Constructor
*
* \param pointer to rendered window
* \param pointer to texture which will display on screen
* \return none
*
***********************************************/
CMainScreen::CMainScreen(sf::RenderWindow *window, sf::Texture* tx, sf::Texture* ui) {
    this->window = window;
    this->backgroundTexture = tx;
    this->uiActive = ui;
    this->components.push_back(MENU_BUTTON(sf::IntRect(13, 10, 284, 55), "Start"));
    this->components.push_back(MENU_BUTTON(sf::IntRect(13, 70, 284, 55), "Options"));
    this->components.push_back(MENU_BUTTON(sf::IntRect(13, 130, 284, 55), "About"));
    this->components.push_back(MENU_BUTTON(sf::IntRect(13, 190, 284, 55), "Exit"));
}

/********************************************//**
 * \brief Displays components on window
 * \return void
 *
 ***********************************************/
int CMainScreen::run() {
    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    sf::Event event;
    int ret = -1;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || (event.type == sf::Event::Closed))
            window->close();
    }
    window->draw(*background);
    for(int i = 0; i < this->components.size(); i++) {
        this->components[i]->stateProvider();
        if(this->components[i]->isClicked()) {
            ret = i;
            //std::cout << ret << std::endl;
        }
        window->draw(*this->components[i]);
    }
    return ret;
}
