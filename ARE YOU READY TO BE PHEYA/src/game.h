#ifndef INCLUDIES_H
#define INCLUDIES_H

#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <cmath>

const float BULL_DT = 0.2;
const float SPEED = 50;
extern float sizeX, sizeY;

class Hero {
public:
	sf::Vector2f pos; 
	sf::Vector2f velocity;
	sf::Vector2f direction; 
	enum { left, right, up, down, jump, stay } state;

	void controlMoving();
	void update(float dt);
};

class Bullet {
public:
	sf::Vector2f pos;
	sf::Vector2f velocity;

	void update(float dt) { 
		pos += velocity * dt;
	}
};

class Map {
public:
	sf::Vector2f size;
	Hero hero;
	std::vector<Bullet> bullets;

	Map() { hero.velocity = sf::Vector2f(0, 0); }
	void update(float dt);
};

#endif