#include "Parallelogram.h"
#include "functions.h"
#include <sstream>
Point Parallelogram::getCenterOfMass() const {
	Point center;
    center.x = (nodes[0].x + nodes[2].x) / 2;
    center.y = (nodes[0].y + nodes[2].y) / 2;
    return center;
}

double Parallelogram::getPerimeter() const {
	return 2 * (sides[0] + sides[1]);
}

void Parallelogram::toString() {
	std::cout << "Фигура: Параллелограм" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl;
}

std::string Parallelogram::convertForFile() {
	std::stringstream ss;
	ss << "f" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Parallelogram::isValid(std::vector<Point>& nodes) {
	if (!Tetragon::isValid(nodes))
		return false;
	if (lengthOfSide(nodes[0], nodes[1]) == lengthOfSide(nodes[2], nodes[3]) && lengthOfSide(nodes[3], nodes[0]) == lengthOfSide(nodes[2], nodes[1]))
		return true;
	return false;
}
Parallelogram* Parallelogram::createParallelogram(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Parallelogram(nodes);
	return nullptr;
}

