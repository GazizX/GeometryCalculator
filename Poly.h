#pragma once
#include "Figure.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Poly : public Figure {
protected:
	std::vector<Point> nodes;
	std::vector<double> sides;
	static Point getCenterOfMass(std::vector<Point>& nodes);
	sf::ConvexShape sh;
	bool isColorSet;
public:
	Poly() {}
	Poly(std::vector<Point> v);
	virtual double getSquare() const override;
	virtual double getPerimeter() const override;
	virtual Point getCenterOfMass() const override;
	virtual void toString() override;
	std::vector<Point> getNodes();
	static bool isValid(std::vector<Point>& nodes);
	static Poly* createPoly(std::vector<Point>& nodes);
	bool isConvex() const;
	virtual std::string convertForFile() override;
	virtual void drawFigure(sf::RenderWindow& window, int width, int height) override;
};