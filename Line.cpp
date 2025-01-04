#include "Line.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML\Graphics.hpp>
Line::Line(Point a, Point c) {
	if (a.x != c.x) {
		k = (a.y - c.y) / (a.x - c.x);
		b = a.y - k * a.x;
		isVertical = false;
	}
	else {
		isVertical = true;
		x = a.x;
	}
}


void Line::toString() {
	std::stringstream ss;
	ss << "Фигура: Прямая" << std::endl;
	if (isVertical) {
		ss << "\tУравнение прямой: x = " << x << std::endl;
	}
	else {
		ss << "\tУравнение прямой: y = ";
		if (k == 0) {
			ss << b;
		}
		else {
			if (k != 1 && k != -1)
				ss << k;
			if (k == -1)
				ss << "-";
			ss << "x";
			if (b > 0) {
				ss << "+" << b;
			}
			else if (b < 0) {
				ss << b;
			}
		}
		ss << std::endl;
	}
	std::cout << ss.str();
}

std::string Line::convertForFile() {
	std::stringstream ss;
	ss << "l" << std::endl;
	ss << 0 << " " << b << std::endl;
	ss << 1 << " " << k + b << std::endl;
	return ss.str();
}

double angleBetween(const Line& line1, const Line& line2) {
	if (line1.isVertical)
		return (180.0 / M_PI) * std::atan(abs(1 / line2.k));
	else if (line2.isVertical)
		return (180.0 / M_PI) * std::atan(abs(1 / line1.k));
	return (180.0 / M_PI) * std::atan(abs((line1.k - line2.k) / (1 + line1.k * line2.k)));
}

Line* Line::createLine(Point a, Point c) {
	if (!(a == c))
		return new Line(a, c);
	return nullptr;
}

void Line::drawFigure(sf::RenderWindow& window, int width, int height) {
	sf::VertexArray line(sf::Lines, 4);
	float k_rad = atan(k);
	sf::Vector2f direction(cos(k_rad), sin(k_rad));
	sf::Vector2f start(width / 2, height / 2);
	line[0].position = sf::Vector2f(-width, k * (-width) + b);
	line[1].position = sf::Vector2f(0, k * (0) + b); 
	line[2].position = sf::Vector2f(0, k * (0) + b); 
	line[3].position = sf::Vector2f(width, k * (width) + b);
	for (int i = 0; i < 4; i++)
		line[i].color = sf::Color::Red;
	window.draw(line);
	
}