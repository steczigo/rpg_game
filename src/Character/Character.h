#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

class Character :  public sf::RectangleShape
{
private:
    sf::Int16 hp;

    void _setDefaultFramePosition()
	{
		this->framePosition[0] = sf::Vector2i(0, 0);
		this->framePosition[1] = sf::Vector2i(0, 1 * this->yFrameSize);
		this->framePosition[2] = sf::Vector2i(0, 2 * this->yFrameSize);
		this->framePosition[3] = sf::Vector2i(0, 3 * this->yFrameSize);
	}
public:

    sf::Vector2i framePosition[4];

    sf::Sprite sprite;
    sf::Texture tex;
    sf::RenderWindow * window;

    const int xFrameSize = 200;
    const int yFrameSize = 200;

    int step = 20;

    float speed = 2.f;
    //Mnoznik predkosci zalezny od klawisza W
    int speedMultiple = 1;
    float rot = 2.f;

    int direction = 2;
	/** 0-up, 1-right, 2-down, 3-left */
    //Smierc
    bool death =false;

    sf::RectangleShape hpinfo; //pasek zdrowia

    //Obsluga prywatnego zdrowia
    void modHp(sf::Int16,bool);
    sf::Int16 getHp();
    void setHp(sf::Int16,bool);
    //Aktualizacja napisow
    void updateInfo();
    void updateTextureRect();
    void checkEvent(sf::Event &);
    void run();

    Character(sf::RenderWindow*,const sf::Vector2f &vec,sf::Texture);
    virtual ~Character();

};

#endif // CHARACTER_H

