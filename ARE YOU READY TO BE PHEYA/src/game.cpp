#include "game.h"

extern float sizeX, sizeY;

bool deleteBullet(Bullet value) {
	if (value.pos.x > sizeX || value.pos.x < 0 || value.pos.y > sizeY || value.pos.y < 0)
		return true;
	return false;
}

void Hero::controlMoving() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		state = left;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
		state = right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
		state = up;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		state = down;
}

void Hero::update(float dt) {
	controlMoving();
	switch (state) {
	case right: velocity.x = SPEED; break;
	case left: velocity.x = -SPEED; break;
	case down: velocity.y = -SPEED; break;
	case up: velocity.y = SPEED; break;
	}
	pos += velocity * dt;
}

void Map::update(float dt) {
	hero.update(dt);
	for (auto& b : bullets) {
		b.update(dt);
	}

	if (hero.pos.x > size.x || hero.pos.x < 0)
		hero.pos.x = size.x;

	if (hero.pos.y > size.y || hero.pos.y < 0)
		hero.pos.y = size.y;

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), deleteBullet), bullets.end());
}