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
CMainScreen::CMainScreen(sf::RenderWindow *window, sf::Texture* tx, sf::Texture* ui) {
    this->window = window;
    this->backgroundTexture = tx;
    /*this->przycisk = new CButton(window);
    this->uiActive = ui;
    this->przycisk->setRect(sf::Vector2i(13, 10), sf::Vector2i(284, 55));
    this->przycisk->loadGUIFile(uiActive);*/
    this->components.push_back(std::shared_ptr<CUIKit>(new CButton(window, ui, sf::IntRect(13, 10, 284, 55), "Start")));
    this->components.push_back(std::shared_ptr<CUIKit>(new CButton(window, ui, sf::IntRect(13, 70, 284, 55), "Exit")));
}

/********************************************//**
 * \brief Displays components on window
 * \return void
 *
 ***********************************************/
int CMainScreen::run() {
    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    //this->background->setScale(1.2, 1.2);
    sf::Event event;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || (event.type == sf::Event::Closed)) window->close();
    }
    std::for_each(components.begin(), components.end(), [this](std::unique_ptr<CUIKit> i) {
        i->stateProvider();
    });
    window->draw(*background);
    window->draw(*przycisk);
}
