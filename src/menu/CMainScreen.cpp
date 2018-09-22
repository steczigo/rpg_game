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
}

int CMainScreen::run() {
    przycisk->setRect(sf::IntRect(50, 10, 150, 30));
    sf::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Red);
    sf::Event event;
    while(window->pollEvent(event)) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
    }
    window->draw(circle);
    window->draw(przycisk);
}
