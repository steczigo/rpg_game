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
    current = new sf::Sprite();
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
    current = &active;
    setFocus(mousePointerInRect());
    setClick(mousePointerInRect() && sf::Mouse::isButtonPressed(sf::Mouse::Left));
    current->setPosition(rect->left, rect->top);
    //shape.setPosition(rect->left, rect->top);
    //shape.setSize(sf::Vector2f(rect->width, rect->height));
    if(this->clicked) this->onClick();
    else if(this->focused) this->onFocus();
    else this->onActive();
}

void CButton::onActive() {
    current = &active;
}

void CButton::onDisable() {}

void CButton::onFocus() {
    current = &focus;
    #ifdef _DEBUG
    cout << "Button focused." << endl;
    #endif // _DEBUG
}

void CButton::onClick() {
    current = &click;
    #ifdef _DEBUG
    cout << "Button clicked." << endl;
    #endif // _DEBUG
}

void CButton::draw(sf::RenderTarget &target,sf::RenderStates states ) const {
    target.draw(*current);
}

void CButton::loadGUIFile(sf::Texture* t) {
    this->texture = t;
    active.setTexture(*t);
    active.setTextureRect(sf::IntRect(13,126,284,55));
    click.setTexture(*t);
    click.setTextureRect(sf::IntRect(13,204,284,55));
    focus.setTexture(*t);
    focus.setTextureRect(sf::IntRect(13,282,284,55));
    current = &active;
}

CButton::~CButton() {
    delete rect, current;
}
