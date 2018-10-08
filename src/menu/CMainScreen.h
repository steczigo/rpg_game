#ifndef CMAINSCREEN_H_INCLUDED
#define CMAINSCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../CScreen.h"
#include "../button/CButton.h"
#include "../UI/CUIKit.h"

class CMainScreen : public CScreen {
private:
    CButton* przycisk;
    sf::Texture* backgroundTexture, *uiActive;
    sf::Sprite* background;
//Methods
public:
    CMainScreen(sf::RenderWindow *window, sf::Texture* tx, sf::Texture* ui);
    ~CMainScreen();

    virtual int run();
private:
    void showMenu();
};

#endif // CMAINSCREEN_H_INCLUDED
