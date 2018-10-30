#ifndef CCURSOR_H_INCLUDED
#define CCURSOR_H_INCLUDED

class CCursor {
private:
    sf::Sprite mouseCursor;
    sf::Texture tex;
    sf::RenderWindow * window;
    bool hide;
public:
    bool isVisible() {return this->hide; }
    void setVisible(bool which) { this->hide = which; }
    CCursor(sf::RenderWindow*, sf::Texture);
    void run();
};

#endif // CCURSOR_H_INCLUDED
