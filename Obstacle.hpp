#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "utils.hpp"

class Obstacle {
public:
  Obstacle();
  Obstacle(sf::Vector2f pos);
  void update(float deltaTime);
  void draw(sf::RenderWindow& window);
private:
  sf::CircleShape sprite;

  float angle;
  int nSprites;
  float spriteTimer;
  float spriteWidth;
  float spriteHeight;
  float spriteAnimation;
  float timeSinceNextSprite;
};

#endif // OBSTACLE_HPP
