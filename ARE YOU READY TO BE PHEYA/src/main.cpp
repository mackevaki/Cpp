#define _USE_MATH_DEFINES
#include "game.h"
#include <iostream>

float sizeX, sizeY;

int main() {
	Map map; 
	std::cout << "Please, enter the desired screen size:" << std::endl;
	std::cin >> map.size.x >> map.size.y;
	sizeX = map.size.x;
	sizeY = map.size.y;
	sf::RenderWindow window(sf::VideoMode(map.size.x, map.size.y), "ARE YOU READY TO BE PHEYA?");
	Bullet bullet;
	sf::Image heroIm;
	heroIm.loadFromFile("hero.png");
	sf::Texture newTexture;
	newTexture.loadFromImage(heroIm);
	sf::Sprite spriteHero;
	spriteHero.setTexture(newTexture);
	sf::Image bulletIm;
	bulletIm.loadFromFile("bull.png");
	sf::Texture bullTexture;
	bullTexture.loadFromImage(bulletIm);
	sf::Sprite spriteBullet;
	sf::Vector2f resize = spriteBullet.getScale();
	spriteBullet.setScale(resize.x/20, resize.y/20);
	spriteBullet.setTexture(bullTexture);

	sf::Clock clock;
	float lastTime = 0;
	float tmp = BULL_DT;
	sf::Vector2u circleSize = spriteHero.getTexture()->getSize();

	while (window.isOpen())	{
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		sf::Time time = clock.getElapsedTime();
		float dt = time.asSeconds() - lastTime;

		spriteHero.setOrigin(circleSize.x / 2, circleSize.y / 2);
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		map.hero.direction = sf::Vector2f(mousePosition.x, mousePosition.y) - map.hero.pos;

		spriteHero.setPosition(map.hero.pos.x, map.hero.pos.y);
		spriteHero.setRotation(90 + (float)atan2f(map.hero.direction.y, map.hero.direction.x) * 180 / M_PI);

		if (!map.bullets.empty())
			for (int i = 0; i < map.bullets.size(); i++) {
				spriteBullet.setPosition(map.bullets[i].pos.x, map.bullets[i].pos.y);
				window.draw(spriteBullet);
			}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			tmp += dt;
			if (tmp >= BULL_DT) {
				tmp = 0;
				bullet.pos = map.hero.pos;
				bullet.velocity = map.hero.direction / sqrt(map.hero.direction.x * map.hero.direction.x + map.hero.direction.y * map.hero.direction.y)*(float)2500;
				map.bullets.push_back(bullet);
			}
		}
		
		window.draw(spriteHero);
		window.draw(spriteBullet);
		window.display();
	
		map.update(dt);
		lastTime = time.asSeconds();
	}

	return 0;
}

