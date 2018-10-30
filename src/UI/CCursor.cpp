#include <SFML/Graphics.hpp>
#include "CCursor.h"

CCursor::CCursor(sf::RenderWindow *wnd, sf::Texture t) {
    this->tex = t;
    this->mouseCursor.setTexture(this->tex);
    this->mouseCursor.setTextureRect(sf::IntRect(697, 265, 32,40));
    this->window = wnd;
    this->window->setMouseCursorVisible(false);
    this->hide = false;
}

void CCursor::run() {
    if(!this->hide) {
        this->mouseCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
        window->draw(this->mouseCursor);
    }
}
