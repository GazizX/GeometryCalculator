#include "Trapezoid.h"
#include "functions.h"
#include "Line.h"
#include <sstream>
void Trapezoid::toString() {
	std::cout << "Фигура: Трапеция" << std::endl
		<< "\tПериметр: " << getPerimeter() << std::endl
		<< "\tПлощадь: " << getSquare() << std::endl
		<< "\tЦентр масс: " << getCenterOfMass() << std::endl;
	if (isIsosceles())
		std::cout << "Свойство: Равнобедренная" << std::endl;
	else if(isRightAngled())
		std::cout << "Свойство: Прямоугольная" << std::endl;
}

std::string Trapezoid::convertForFile() {
	std::stringstream ss;
	ss << "t" << std::endl;
	for (int i = 0; i < 4; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Trapezoid::isValid(std::vector<Point>& nodes) {
	if (!Tetragon::isValid(nodes))
		return false;
	Line a(nodes[0], nodes[1]);
	Line b(nodes[1], nodes[2]);
	Line c(nodes[2], nodes[3]);
	Line d(nodes[3], nodes[0]);
	if (sin(angleBetween(a, c)) == 0 && sin(angleBetween(b, d)) == 0 || sin(angleBetween(a, c)) != 0 && sin(angleBetween(b, d)) != 0)
		return false;
	return true;
}
Trapezoid* Trapezoid::createTrapezoid(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Trapezoid(nodes);
	return nullptr;
}
bool Trapezoid::isRightAngled() const {
	Line a(nodes[0], nodes[1]);
	Line b(nodes[1], nodes[2]);
	Line c(nodes[2], nodes[3]);
	Line d(nodes[3], nodes[0]);
	if (cos(angleBetween(a, b)) == 0 || cos(angleBetween(b, c)) == 0 || cos(angleBetween(c, d)) == 0 || cos(angleBetween(d, a)) == 0)
		return true;
	return false;
}
bool Trapezoid::isIsosceles() const {
	if (sides[0] == sides[2] || sides[1] == sides[3])
		return true;
	return false;
}