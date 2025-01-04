#include "Tetragon.h"
#include <iostream>
#include "functions.h"
#include "Line.h"
#include <sstream>
void Tetragon::toString() {
	std::cout << "Фигура: Четырехугольник" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl
		<< "\tСвойство: " << (isConvex() ? "Выпуклый" : "Невыпуклый") << std::endl;
}

std::string Tetragon::convertForFile() {
	std::stringstream ss;
	ss << "d" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

double Tetragon::getSquare() const {
	double diag1 = lengthOfSide(nodes[0], nodes[2]);
	double diag2 = lengthOfSide(nodes[1], nodes[3]);
	double phi = angleBetween(Line(nodes[0], nodes[2]), Line(nodes[1], nodes[3]));
	return (diag1 * diag2 * sin(phi)) / 2;
}

bool Tetragon::isValid(std::vector<Point>& nodes) {
	return (Poly::isValid(nodes) && nodes.size() == 4) ? true : false;
}
Tetragon* Tetragon::createTetragon(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Tetragon(nodes);
	return nullptr;
}