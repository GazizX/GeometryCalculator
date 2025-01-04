#include "Rhomb.h"
#include "Line.h"
#include "functions.h"
#include <sstream>
double Rhomb::getPerimeter() const {
	return sides[0] * 4;
}
void Rhomb::toString() {
	std::cout << "Фигура: Ромб" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl;
}
std::string Rhomb::convertForFile() {
	std::stringstream ss;
	ss << "r" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Rhomb::isValid(std::vector<Point>& nodes) {
	if (!Parallelogram::isValid(nodes))
		return false;
	Line a(nodes[0], nodes[2]);
	Line b(nodes[1], nodes[3]);
	if (cos(angleBetween(a, b) != 0))
		return false;
	return true;
}

Rhomb* Rhomb::createRhomb(std::vector<Point>&nodes){
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Rhomb(nodes);
	return nullptr;
}