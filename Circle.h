#pragma once
#include "Figure.h"
class Circle : public Figure {
	double radius;
	Point center;
	bool isColorSet;
	sf::CircleShape cs;
public:
	Circle(double R, Point C) : radius(R), center(C), isColorSet(false) {};
	static Circle* createCircle(double R, Point C);
	double getSquare() const override;
	double getPerimeter() const override;
	Point getCenterOfMass() const override;
	double getRadius() const;
	void toString() override;
	std::string convertForFile() override;
	void drawFigure(sf::RenderWindow& window, int width, int height) override;
};