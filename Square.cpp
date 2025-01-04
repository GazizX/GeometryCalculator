#include "Square.h"
#include "functions.h"
#include <sstream>
void Square::toString() {
	std::cout << "Фигура: Квадрат" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl;
}

std::string Square::convertForFile() {
	std::stringstream ss;
	ss << "q" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Square::isValid(std::vector<Point>& nodes) {
	if(!Rect::isValid(nodes))
		return false;
	if (lengthOfSide(nodes[0], nodes[1]) != lengthOfSide(nodes[1], nodes[2]))
		return false;
	return true;
}
Square* Square::createSquare(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Square(nodes);
	return nullptr;
}