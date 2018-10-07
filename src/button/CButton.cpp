#include <SFML/Graphics.hpp>
#include "CButton.h"
#include <iostream>

using namespace std;

/********************************************//**
 * \brief Function is setting a button title
 *
 * \param sf::String, title
 * \return void
 *
 ***********************************************/
void CButton::setText(sf::String str) {
    this->title = str;
}

/********************************************//**
 * \brief Function is setting dimensions of the button
 *
 * \param sf::Vector2i, position of the box
 * \param sf::Vector2i, box size
 * \return void
 *
 ***********************************************/
void CButton::setRect(sf::Vector2i v, sf::Vector2i b) {
    this->rect = new sf::IntRect(v, b);
}

/********************************************//**
 * \brief Function is setting dimensions of the button
 *
 * \param sf::IntRect, position and size of the box
 * \return void
 *
 ***********************************************/
void CButton::setRect(sf::IntRect r) {
    this->rect = new sf::IntRect(r);
}

/********************************************//**
 * \brief Constructor
 *
 * \param sf::RenderWindow* ,pointer to rendered window
 *
 ***********************************************/
CButton::CButton(sf::RenderWindow* r) {
    this->window = r;
    current = new sf::Sprite();
}

/********************************************//**
 * \brief Check the button is clicked
 * \return bool
 *
 ***********************************************/
bool CButton::isClicked() {
    return this->clicked;
}

/********************************************//**
 * \brief Check the button is focused
 * \return bool
 *
 ***********************************************/
bool CButton::isFocused() {
    return this->focused;
}

/********************************************//**
 * \brief Check the mouse position is in the generated button
 * \return bool
 *
 ***********************************************/
bool CButton::mousePointerInRect() {
    this->mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f pos = this->window->mapPixelToCoords(this->mousePos);
    return this->rect->contains(pos.x, pos.y);
}

/********************************************//**
 * \brief Set the button focused
 *
 * \param bool, button state
 * \return void
 *
 ***********************************************/
void CButton::setFocus(bool which) {
    this->focused = which;
}

/********************************************//**
 * \brief Set the button focused
 *
 * \param bool, button state
 * \return void
 *
 ***********************************************/
void CButton::setClick(bool which) {
    this->clicked = which;
}

/********************************************//**
 * \brief Setting button properties when something happen
 * \return void
 *
 ***********************************************/
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

/********************************************//**
 * \brief Is running in each frame if the button is active
 * \return void
 *
 ***********************************************/
void CButton::onActive() {
    current = &active;
}

/********************************************//**
 * \brief Is running in each frame if the button is disabled
 * \return void
 *
 ***********************************************/
void CButton::onDisable() {}

/********************************************//**
 * \brief Is running in each frame if the button is focused
 * \return void
 *
 ***********************************************/
void CButton::onFocus() {
    current = &focus;
    #ifdef _DEBUG
    cout << "Button focused." << endl;
    #endif // _DEBUG
}

/********************************************//**
 * \brief Is running in each frame if the button is clicked
 * \return void
 *
 ***********************************************/
void CButton::onClick() {
    current = &click;
    #ifdef _DEBUG
    cout << "Button clicked." << endl;
    #endif // _DEBUG
}

/********************************************//**
 * \brief This function draw the button on your window
 * \return void
 *
 ***********************************************/
void CButton::draw(sf::RenderTarget &target,sf::RenderStates states ) const {
    target.draw(*current);
}

/********************************************//**
 * \brief Function prepare button sprites from loaded texture
 * \return void
 *
 ***********************************************/
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

/********************************************//**
 * \brief Destructor
 * \return none
 *
 ***********************************************/
CButton::~CButton() {
    delete rect, current;
}
