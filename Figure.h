#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>
class Figure {
public:
	virtual double getSquare() const = 0;
	virtual double getPerimeter() const = 0;
	virtual Point getCenterOfMass() const = 0;
	virtual void toString() = 0;
	virtual std::string convertForFile() = 0;
	virtual void drawFigure(sf::RenderWindow& window, int width, int height) = 0;
};