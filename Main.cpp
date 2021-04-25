// RayCast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Wall.h"
#include "Source.h"

int main()
{
    std::cout << "Hello \n";

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "RayCasting", sf::Style::Close, settings);
	
	Source s(200, 650, 180);
	std::vector<Wall> walls;
	walls.emplace_back(300, 50, 800, 600);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				s.move(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			}
		}
		window.clear(sf::Color::Black);
		s.checkWall(walls);
		s.draw(window);

		for (int i = 0; i < walls.size(); ++i) {
			walls.at(i).draw(window);
		}
		window.display();
	}
}
