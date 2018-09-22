#include <SFML/Graphics.hpp>
#include "CButton.h"
#include <iostream>

using namespace std;

void CButton::setText(sf::String str) {
    this->title = str;
}
void CButton::setRect(sf::Vector2i v, sf::Vector2i b) {
    this->rect = new sf::IntRect(v, b);
}
void CButton::setRect(sf::IntRect r) {
    this->rect = new sf::IntRect(r);
}

bool CButton::isClicked() {
    return this->clicked;
}

bool CButton::mousePointerInRect() {
    this->mousePos = sf::Mouse::getPosition();
    return this->rect->contains(mousePos);
}
void CButton::setFocus(bool which) {
    this->focused = which;
}

void CButton::draw(sf::RenderTarget &target, const sf::RenderStates states ) {
    setFocus(mousePointerInRect());
    sf::RectangleShape shape;
    shape.setPosition(rect->left, rect->top);
    shape.setSize(sf::Vector2f(rect->width, rect->height));
    if(this->focused) {
        shape.setFillColor(sf::Color::Green);
        cout << "Button focused." << endl;
    }
    else {
        shape.setFillColor(sf::Color::Red);
    }
    target.draw(shape, states);
}

CButton::~CButton() {
    delete rect, window;
}
