#ifndef CMAINSCREEN_H_INCLUDED
#define CMAINSCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../CScreen.h"
#include "../button/CButton.h"

class CMainScreen : public CScreen {
private:
    CButton* przycisk;

//Methods
public:
    CMainScreen(sf::RenderWindow *window);
    virtual int run();
private:
    void showMenu();
};

#endif // CMAINSCREEN_H_INCLUDED
