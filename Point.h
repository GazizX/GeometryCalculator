#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
struct Point {
	float x, y;
	Point() : x(0), y(0) {}
	Point(float x, float y) : x(x), y(y) {}
	friend std::ostream& operator << (std::ostream& os, const Point& p);
	bool operator == (const Point& other);
	std::string convertForFile();
	void drawFigure(sf::RenderWindow& window, int width, int height);
};