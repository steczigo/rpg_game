#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

class CButton : public sf::Drawable {
private:
    sf::Window * window;
    sf::String title;
    sf::IntRect * rect;
    bool clicked;
    bool focused;
    sf::Vector2i mousePos;
public:
    void setText(sf::String);
    void setRect(sf::Vector2i, sf::Vector2i);
    void setRect(sf::IntRect r);
    bool isClicked();
    bool isFocused();
    virtual void draw(sf::RenderTarget &target, const sf::RenderStates states );
    ~CButton();
private:
    bool mousePointerInRect();
    void setFocus(bool);
};

#endif // CBUTTON_H_INCLUDED
