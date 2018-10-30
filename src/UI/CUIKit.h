#ifndef CUIKIT_H_INCLUDED
#define CUIKIT_H_INCLUDED

class CUIKit : public sf::Drawable {
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

    //sf::String title;
    //sf::Text title;
    sf::IntRect* rect;
    sf::Texture* texture;
    sf::Font font;
    sf::Text title;
    sf::IntRect irActived;
    sf::IntRect irFocused;
    sf::IntRect irClicked;
    sf::IntRect irDisabled;

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
    virtual void setFocus(bool) = 0;
    virtual void setClick(bool) = 0;
public:
    virtual void setText(sf::String) = 0;
    virtual void setRect(sf::Vector2i, sf::Vector2i) = 0;
    virtual void setRect(sf::IntRect) = 0;
    virtual bool isClicked() = 0;
    virtual bool isFocused() = 0;
    virtual void loadGUIFile(sf::Texture*) = 0;
    virtual void setText(std::string) = 0;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;

    virtual ~CUIKit() {};
};

#endif // CUIKIT_H_INCLUDED
