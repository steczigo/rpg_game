#ifndef CSCREEN_H_INCLUDED
#define CSCREEN_H_INCLUDED

class CScreen {
public:
    sf::RenderWindow *window;
    virtual int run() = 0;
};

#endif // CSCREEN_H_INCLUDED
