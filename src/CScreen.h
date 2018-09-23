#ifndef CSCREEN_H_INCLUDED
#define CSCREEN_H_INCLUDED

#include <vector>
#include "UI/CUIKit.h"

class CScreen {
protected:
    sf::RenderWindow *window;
    std::vector<CUIKit> components;
public:
    virtual int run() = 0;
};

#endif // CSCREEN_H_INCLUDED
