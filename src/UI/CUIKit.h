#ifndef CUIKIT_H_INCLUDED
#define CUIKIT_H_INCLUDED

class CUIKit {
protected:
    bool clicked;
    bool focused;
    bool disabled;

    sf::RenderWindow * window;

    sf::Sprite active;
    sf::Sprite click;
    sf::Sprite focus;
    sf::Sprite disable;

    sf::Sprite* current;

public:
    sf::Sprite getActivedSprite() { return this->active; }
    sf::Sprite getClickedSprite() { return this->click; }
    sf::Sprite getFocusedSprite() { return this->focus; }
    sf::Sprite getDisabledSprite() { return this->disable; }
    void setActivedSprite(sf::Sprite spr) { this->active = spr; }
    void setClickedSprite(sf::Sprite spr) { this->click = spr; }
    void setFocusedSprite(sf::Sprite spr) { this->focus = spr; }
    void setDisabledSprite(sf::Sprite spr) { this->disable = spr; }

    virtual void stateProvider() = 0;
protected:
    virtual void onClick() = 0;
    virtual void onFocus() = 0;
    virtual void onActive() = 0;
    virtual void onDisable() = 0;
};

#endif // CUIKIT_H_INCLUDED
