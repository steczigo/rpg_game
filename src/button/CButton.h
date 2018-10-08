#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

#include "../UI/CUIKit.h"

class CButton : public sf::Drawable, public CUIKit {
private:
    sf::String title;
    sf::IntRect* rect;
    sf::Vector2i mousePos;
    sf::Texture* texture;
    sf::Font font;
public:
    CButton(sf::RenderWindow*);
    CButton(sf::RenderWindow*, sf::Texture *,  sf::IntRect, sf::String);
    ~CButton();

    void setText(sf::String);
    void setRect(sf::Vector2i, sf::Vector2i);
    void setRect(sf::IntRect);
    bool isClicked();
    bool isFocused();
    void loadGUIFile(sf::Texture* t);
    void setText(std::string);

    virtual void stateProvider();
    virtual void onFocus();
    virtual void onClick();
    virtual void onDisable();
    virtual void onActive();
protected:
    void setFocus(bool);
    void setClick(bool);
private:
    bool mousePointerInRect();
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // CBUTTON_H_INCLUDED
