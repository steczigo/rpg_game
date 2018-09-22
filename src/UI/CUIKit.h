#ifndef CUIKIT_H_INCLUDED
#define CUIKIT_H_INCLUDED

class CUIKit {
protected:
    bool clicked;
    bool focused;

    sf::RenderWindow * window;

    sf::Sprite active;
    sf::Sprite click;
    sf::Sprite focus;
    sf::Sprite disable;

    virtual void onClick() = 0;
    virtual void onFocus() = 0;
    virtual void onActive() = 0;
    virtual void onDisable() = 0;
};

#endif // CUIKIT_H_INCLUDED
