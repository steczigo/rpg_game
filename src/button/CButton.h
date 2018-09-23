#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

#include "../UI/CUIKit.h"

class CButton : public sf::Drawable, public CUIKit {
private:
    sf::String title;
    sf::IntRect* rect;
    sf::Vector2i mousePos;
    sf::RectangleShape shape;
    sf::Texture* texture;
public:
    CButton(sf::RenderWindow*);
    void setText(sf::String);
    void setRect(sf::Vector2i, sf::Vector2i);
    void setRect(sf::IntRect);
    bool isClicked();
    bool isFocused();
    ~CButton();
    void stateProvider();
    void loadGUIFile(sf::Texture* t);
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
