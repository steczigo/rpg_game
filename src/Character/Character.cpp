#include "Character.h"
#include <iostream>
using namespace std;


Character::Character(sf::RenderWindow *wnd,const sf::Vector2f &vec,sf::Texture t)
{

    this->window = wnd;
    this->setSize(vec);
    this->tex = t;
	this->_setDefaultFramePosition();
	this->updateTextureRect();
	this->sprite.setTexture(this->tex);
}

void Character::updateTextureRect()
{
	this->sprite.setTextureRect(sf::IntRect
                      (this->framePosition[this->direction].x, this->framePosition[this->direction].y, this->xFrameSize, this->yFrameSize
	));
}

void Character::updateInfo()
{
      this->hpinfo.setSize(sf::Vector2f(this->getHp()*2,5)) ;
      this->hpinfo.setPosition(this->getPosition().x-24,this->getPosition().y-40);
}

void Character::modHp(sf::Int16 hpmod, bool play) {
   if (this->death) return; // nie zmieniam jak ju¿ wygra³
   this->hp += hpmod;
   //if (play && hpmod > 0) this->sfx.play("heal",100,false,1.f,false);
   //if (play && hpmod < 0) this->sfx.play("hit",100,false,1.f,false);

}

void Character::run()
{
    cout<<"dziala"<<endl;
    //this->sprite.setPosition(sf::Vector2f(150,150));
        window->draw(this->sprite);
}


sf::Int16 Character::getHp() { return this->hp; }

void Character::setHp(sf::Int16 shp, bool play){
   if (this->death) return;
   //if (play && this->hp > shp) this->sfx.play("hit",100,false,1.f,false);
   //else if (play && this->hp < shp) this->sfx.play("heal",100,false,1.f,false);
   this->hp = shp;
}


Character::~Character(){}

void Character::checkEvent(sf::Event &e)
{
	int stepx, stepy = 0;
	if (e.type == sf::Event::KeyPressed)
        {
		switch (e.key.code)
		{
		case sf::Keyboard::Up:
			this->direction = 0;
			stepy = -this->step;
			stepx = 0;
			break;
		case sf::Keyboard::Right:
			this->direction = 1;
			stepy = 0;
			stepx = this->step;
			break;
		case sf::Keyboard::Down:
			this->direction = 2;
			stepy = this->step;
			stepx = 0;
			break;
		case sf::Keyboard::Left:
			this->direction = 3;
			stepy = 0;
			stepx = -this->step;
			break;
		default: return;
		}
		this->sprite.setPosition(this->getPosition().x + stepx, this->getPosition().y + stepy);
		std::cout << this->getPosition().x << " " << this->getPosition().y << "\n";
		this->updateTextureRect();
	}
}
