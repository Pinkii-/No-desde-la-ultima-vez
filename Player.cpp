#include "Player.hpp"
#include "Resources.hpp"

Player::Player() {}

Player::Player(sf::Vector2f pos, sf::Vector2f speed) :
    pos(pos), speed(speed){
pos.x = 0;
pos.y = 0;
    spriteTimer = 0.0;
    spriteAnimation = 0.0;
    timeSinceNextSprite = 0.2;
    angle = speedToAngle(speed);
    sprite.setTexture(Resources::ship);
    spriteHeight = Resources::ship.getSize().y;
    spriteWidth = Resources::ship.getSize().x/15;
    sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);

}

void Player::update(float deltaTime) {
    evoluciona(deltaTime);
    sprite.setPosition(pos);
    spriteTimer += deltaTime;
    if(spriteTimer >= timeSinceNextSprite){
        ++spriteAnimation;
        spriteAnimation = (int)spriteAnimation % 15;
    }
}

void Player::draw(sf::RenderWindow &window) {
    sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
    sprite.setRotation(angle);
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() {
    return pos;
}

//Private functions

void Player::evoluciona(float fdelta)
{
  double delta=fdelta;
  point p=vector2point(pos);
  point v=vector2point(speed);
  point c=vector2point(camaleonPos);
  if (not licked) {
    p+=v*delta;
    pos=point2vector(p);
    return;
  }
  if (not tensioning) {
    p+=v*delta;
    pos=point2vector(p);
    if (prodesc(v,p-c)>=0)
      tensioning=true;
    return;
  }
  p-=c;
  double modulov=abs(v);
  double desp=modulov*delta;
  double r=abs(p);
  double alfa=desp/r;
  int signo=prodvec(p,v)>0?1:-1;
  p*=std::polar(1.0,signo*alfa);
  v=p*std::polar(1.0,signo*M_PI/2.0);
  v=(modulov/abs(v))*v;
  p+=c;
  pos=point2vector(p);
  speed=point2vector(v);
}
