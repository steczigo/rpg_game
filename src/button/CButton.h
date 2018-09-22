#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

class CButton : public sf::Drawable {
private:
    sf::RenderWindow * window;
    sf::String title;
    sf::IntRect * rect;
    bool clicked;
    bool focused;
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
protected:
    bool mousePointerInRect();
    void setFocus(bool);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // CBUTTON_H_INCLUDED
