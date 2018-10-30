#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

#include "../UI/CUIKit.h"

class CButton : public CUIKit {
public:
    CButton(sf::RenderWindow*);
    CButton(sf::RenderWindow*, sf::Texture *,sf::IntRect, sf::IntRect, sf::IntRect, sf::IntRect ,sf::IntRect, sf::String);
    virtual ~CButton();

    virtual void setText(sf::String);
    virtual void setRect(sf::Vector2i, sf::Vector2i);
    virtual void setRect(sf::IntRect);
    virtual bool isClicked();
    virtual bool isFocused();
    virtual void loadGUIFile(sf::Texture* t);
    virtual void setText(std::string);
    virtual float set_text_position(std::string, sf::IntRect);

    virtual void stateProvider();
    virtual void onFocus();
    virtual void onClick();
    virtual void onDisable();
    virtual void onActive();
protected:
    virtual void setFocus(bool);
    virtual void setClick(bool);
    bool mousePointerInRect();
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif // CBUTTON_H_INCLUDED
