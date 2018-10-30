#ifndef CBUTTONSTATE_H_INCLUDED
#define CBUTTONSTATE_H_INCLUDED

class CButtonState {
private:
    sf::Sprite sprite;
public:
    sf::Font font;
    sf::Texture texture;
    sf::Text text;

    CButtonState() {}
    sf::Sprite getSprite();
};

#endif // CBUTTONSTATE_H_INCLUDED
