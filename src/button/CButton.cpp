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

CButton::CButton(sf::RenderWindow* r) {
    this->window = r;
}

bool CButton::isClicked() {
    return this->clicked;
}

bool CButton::isFocused() {
    return this->focused;
}

bool CButton::mousePointerInRect() {
    this->mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f pos = this->window->mapPixelToCoords(this->mousePos);
    return this->rect->contains(pos.x, pos.y);
}

void CButton::setFocus(bool which) {
    this->focused = which;
}

void CButton::setClick(bool which) {
    this->clicked = which;
}

void CButton::stateProvider() {
    setFocus(mousePointerInRect());
    setClick(mousePointerInRect() && sf::Mouse::isButtonPressed(sf::Mouse::Left));
    shape.setPosition(rect->left, rect->top);
    shape.setSize(sf::Vector2f(rect->width, rect->height));
    if(this->clicked) this->onClick();
    else if(this->focused) this->onFocus();
    else this->onActive();
}

void CButton::onActive() {
    shape.setFillColor(sf::Color::Red);
}

void CButton::onDisable() {}

void CButton::onFocus() {
    shape.setFillColor(sf::Color::Green);
    #ifdef _DEBUG
    cout << "Button focused." << endl;
    #endif // _DEBUG
}

void CButton::onClick() {
    shape.setFillColor(sf::Color::Blue);
    #ifdef _DEBUG
    cout << "Button clicked." << endl;
    #endif // _DEBUG
}

void CButton::draw(sf::RenderTarget &target,sf::RenderStates states ) const {
    target.draw(shape);
}

void CButton::loadGUIFile(sf::Texture* t) {
    this->texture = t;
}

CButton::~CButton() {
    delete rect;
}
