#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>
#include "functions.h"
double Circle::getSquare() const {
	return M_PI * pow(radius, 2);
}
double Circle::getPerimeter() const {
	return 2 * M_PI * radius;
}
Point Circle::getCenterOfMass() const {
	return center;
}
double Circle::getRadius() const {
	return radius;
}
void Circle::toString() {
	std::cout << "Фигура: Круг" << std::endl
		<< "\tРадиус: " << getRadius() << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << center << std::endl;
}
Circle* Circle::createCircle(double R, Point C) {
	if (R > 0) {
		return new Circle(R, C);
	}
	return nullptr;
}
std::string Circle::convertForFile() {
	std::stringstream ss;
	ss << "a" << std::endl;
	ss << radius << std::endl << center.x << " " << center.y << std::endl;
	return ss.str();
}

void Circle::drawFigure(sf::RenderWindow& window, int width, int height) {
	cs.setRadius(radius);
	cs.setPosition(center.x, center.y);
	if (!isColorSet) {
		float r = rand() % 256;
		float g = rand() % 256;
		float b = rand() % 256;
		cs.setFillColor(sf::Color(r, g, b, 200));
		cs.setOutlineColor(sf::Color(r, g, b));
		isColorSet = true;
	}
	cs.setOrigin(radius, radius);
	window.draw(cs);
}