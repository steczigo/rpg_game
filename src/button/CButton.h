#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

#include "../UI/CUIKit.h"

class CButton : public sf::Drawable, public CUIKit {
private:
    sf::String title;
    sf::IntRect * rect;
    sf::Vector2i mousePos;
    sf::RectangleShape shape;
public:
    CButton(sf::RenderWindow* r);
    void setText(sf::String);
    void setRect(sf::Vector2i, sf::Vector2i);
    void setRect(sf::IntRect);
    bool isClicked();
    bool isFocused();
    ~CButton();
    void stateProvider();
    virtual void onFocus();
    virtual void onClick();
    virtual void onDisable();
    virtual void onActive();
protected:
    void setFocus(bool);
    void setClick(bool);
private:
    bool mousePointerInRect();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // CBUTTON_H_INCLUDED
