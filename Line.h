#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>
class Line{
	double k;
	double b;
	bool isVertical;
	double x;
public:
	Line(){}
	Line(double K, double B) : k(K), b(B), isVertical(false), x(0){}
	Line(Point a, Point c);
	void toString();
	friend double angleBetween(const Line& line1, const Line& line2);
	static Line* createLine(Point a, Point c);
	std::string convertForFile();
	void drawFigure(sf::RenderWindow& window, int width, int height);
};