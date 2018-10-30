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
    this->title = sf::Text(str, font, 30);
}

/********************************************//**
 * \brief Function is setting a button title
 *
 * \param std::string, title
 * \return void
 *
 ***********************************************/
void CButton::setText(std::string str) {
    this->title = sf::Text(str, font, 30);
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
 * \brief Function is setting position of text
 *        which is displayed on top of the button
 *
 * \param std::string, the string you want to display
          (here you use it to get length of the string)
          sf::IntRect, position and size of the box
          (you use the box parameters to place text
           on screen)
 * \return float
 *
 ***********************************************/
float CButton::set_text_position(std::string str, sf::IntRect rect)
{
    int len = str.length();
    float str_start = (rect.left) + ((rect.width)/2 - 6*len);
    return str_start;
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
    focused = false;
    clicked = false;
    disabled = false;
}

/********************************************//**
 * \brief Constructor
 *
 * \param sf::RenderWindow* ,pointer to rendered window
 * \param sf::Texture* ,pointer to button GUI texture
 * \param sf::IntRect ,actived texture rect
 * \param sf::IntRect ,clicked texture rect
 * \param sf::IntRect ,focused texture rect
 * \param sf::IntRect ,disabled texture rect
 * \param sf::IntRect ,button rect on window
 * \param sf::String* ,title displayed on button
 *
 ***********************************************/
CButton::CButton(sf::RenderWindow* r, sf::Texture *tx, sf::IntRect irActived, sf::IntRect irClicked, sf::IntRect irFocused, sf::IntRect irDisabled, sf::IntRect rect, sf::String str) {
    this->window = r;
    current = new sf::Sprite();
    focused = false;
    clicked = false;
    disabled = false;
    this->irActived = irActived;
    this->irDisabled = irDisabled;
    this->irClicked = irClicked;
    this->irFocused = irFocused;
    this->loadGUIFile(tx);
    this->setRect(rect);
    this->setText(str);
    if (!font.loadFromFile("../rpg_game-master/fonts/hand.ttf"))
        #ifdef _DEBUG
        cout << "Error loading font\n";
        #endif // _DEBUG
    this->font.loadFromFile("../rpg_game-master/fonts/hand.ttf");
    this->title.setFont(font);
    this->title.setPosition(set_text_position(str, rect), (this->rect->top)+5);
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
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f pos = this->window->mapPixelToCoords(mousePos);
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

    if(this->disabled) this->onDisable();
    else if(this->clicked) this->onClick();
    else if(this->focused) this->onFocus();
    else this->onActive();

    current->setPosition(rect->left, rect->top);
}

/********************************************//**
 * \brief Is running in each frame if the button is active
 * \return void
 *
 ***********************************************/
void CButton::onActive() {
    current = &active;
    //current->setTexture(*this->texture);
    //current->setTextureRect(sf::IntRect(13,126,284,55));
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
    //current->setTexture(*this->texture);
    //current->setTextureRect(sf::IntRect(13,282,284,55));
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
    //current->setTexture(*this->texture);
    //current->setTextureRect(sf::IntRect(13,204,284,55));
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
    target.draw(this->title);
}

/********************************************//**
 * \brief Function prepare button sprites from loaded texture
 * \return void
 *
 ***********************************************/
void CButton::loadGUIFile(sf::Texture* t) {
    this->texture = t;
    active.setTexture(*t);
    active.setTextureRect(irActived);
    click.setTexture(*t);
    click.setTextureRect(irClicked);
    focus.setTexture(*t);
    focus.setTextureRect(irFocused);
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
