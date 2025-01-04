#include "MyRect.h"
#include "Line.h"
#include "functions.h"
#include <sstream>
double Rect::getSquare() const {
	return sides[0] * sides[1];
}
void Rect::toString() {
	std::cout << "Фигура: Прямоугольник" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl;
}

std::string Rect::convertForFile() {
	std::stringstream ss;
	ss << "g" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Rect::isValid(std::vector<Point>& nodes) {
	if (!Parallelogram::isValid(nodes))
		return false;
	Line a(nodes[0], nodes[1]);
	Line b(nodes[1], nodes[2]);
	if (angleBetween(a,b) != 90)
		return false;
	return true;
}
Rect* Rect::createRect(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Rect(nodes);
	return nullptr;
}
