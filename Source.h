#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Beam.h"

class Source {
public:
	Source(int x, int y, int beamCount);
	~Source();
	void draw(sf::RenderWindow &window) const;
	void move(int x, int y);
	void checkWall(const std::vector<Wall> &wall);

private:
	int m_x, m_y, m_beamCount;
	std::vector<Beam> m_beams;
};