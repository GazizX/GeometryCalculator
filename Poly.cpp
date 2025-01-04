#include "Poly.h"
#include "functions.h"
#include <sstream>
Poly::Poly(std::vector<Point> v) : nodes(v) {
	
	for (int i = 0; i < nodes.size() - 1; i++) {
		sides.push_back(lengthOfSide(nodes[i], nodes[i + 1]));
	}
	sides.push_back(lengthOfSide(nodes[0], nodes[nodes.size() - 1]));
	isColorSet = false;
}

std::vector<Point> Poly::getNodes() {
	return nodes;
}

double Poly::getSquare() const {
	double s = 0;
	for (int i = 0; i < nodes.size() - 2; i++) {
		s += nodes[i].x * nodes[i + 1].y;
		s -= nodes[i + 1].x * nodes[i].y;
	}
	s += nodes[nodes.size() - 1].x * nodes[0].y - nodes[0].x * nodes[nodes.size() - 1].y;
	return abs(s) / 2;
}
double Poly::getPerimeter() const {
	double p = 0;
	for (int i = 0; i < nodes.size() - 1; i++) {
		p += lengthOfSide(nodes[i], nodes[i + 1]);
	}
	p += lengthOfSide(nodes[0], nodes[nodes.size() - 1]);
	return p;
}
Point Poly::getCenterOfMass() const {
	float x_center = 0;
	float y_center = 0;
	for (int i = 0; i < nodes.size(); i++) {
		x_center += nodes[i].x;
		y_center += nodes[i].y;
	}
	Point center(x_center / nodes.size(), y_center / nodes.size());
	return center;
}

Point Poly::getCenterOfMass(std::vector<Point>& nodes){
	float x_center = 0;
	float y_center = 0;
	for (int i = 0; i < nodes.size(); i++) {
		x_center += nodes[i].x;
		y_center += nodes[i].y;
	}
	Point center(x_center / nodes.size(), y_center / nodes.size());
	return center;
}


void Poly::toString() {
	std::cout << "Фигура: Многоугольник" << std::endl
		<< "\tКоличество углов: " << nodes.size() << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl
		<< "\tСвойство: " << (isConvex() ? "Выпуклый" : "Невыпуклый") << std::endl;
}

std::string Poly::convertForFile() {
	std::stringstream ss;
	ss << "b" << std::endl;
	for (int i = 0; i < nodes.size(); i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Poly::isValid(std::vector<Point>& nodes){
	if (nodes.size() < 3)
		return false;
	for (int i = 0; i < nodes.size() - 2; i++) {
		if (nodes[i] == nodes[i + 1] || areInLine(nodes[i], nodes[i + 1], nodes[i + 2]))
			return false;
	}
	if (nodes[nodes.size() - 2] == nodes[nodes.size() - 1])
		return false;
	return true;
}

Poly* Poly::createPoly(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (Poly::isValid(nodes))
		return new Poly(nodes);
	return nullptr;
}

bool Poly::isConvex() const {
	bool isRight = vectorProduct(nodes[nodes.size() - 2], nodes[nodes.size() - 1], nodes[0]) > 0;
	for (int i = 0; i < nodes.size() - 2; i++) {
		double vec = vectorProduct(nodes[i], nodes[i + 1], nodes[i + 2]);
		if (vec == 0) continue;
		if ((vec > 0) != isRight) {
			return false;
		}
	}
	return true;
}

void Poly::drawFigure(sf::RenderWindow& window, int width, int height) {
	sh.setPointCount(nodes.size());
	for (int i = 0; i < nodes.size(); i++) {
		sh.setPoint(i, sf::Vector2f(nodes[i].x, nodes[i].y));
	}
	if (!isColorSet) {
		float r = rand() % 256;
		float g = rand() % 256;
		float b = rand() % 256;
		sh.setFillColor(sf::Color(r, g, b, 200));
		sh.setOutlineColor(sf::Color(r, g, b));
		isColorSet = true;
	}
	sh.setOrigin(getCenterOfMass().x, getCenterOfMass().y);
	sh.setPosition(getCenterOfMass().x, getCenterOfMass().y);
	window.draw(sh);
}