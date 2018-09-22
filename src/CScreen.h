#ifndef CSCREEN_H_INCLUDED
#define CSCREEN_H_INCLUDED

#include <vector>

class CScreen {
public:
    //std::vector<CUIKit> fd;
    sf::RenderWindow *window;
    virtual int run() = 0;
};

#endif // CSCREEN_H_INCLUDED
