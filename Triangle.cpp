#include "Triangle.h"
#include "functions.h"
#include <sstream>
Triangle::Triangle(std::vector<Point> v) : Poly(v){
	a = Line(nodes[0], nodes[1]);
	b = Line(nodes[1], nodes[2]);
	c = Line(nodes[2], nodes[0]);
}
void Triangle::toString() {
	std::cout << "������: �����������" << std::endl
		<< "\t��������: " << getPerimeter() << std::endl
		<< "\t�������: " << getSquare() << std::endl
		<< "\t����� ����: " << getCenterOfMass() << std::endl
		<< "\t�� ��������: ";
	if (isEquilateral())
		std::cout << "��������������" << std::endl;
	else if(isIsosceles())
		std::cout << "��������������" << std::endl;
	else
		std::cout << "��������������" << std::endl;
	std::cout << "\t�� �����: ";
	if (isRightAngled())
		std::cout << "�������������" << std::endl;
	else if (isAcuteAngled())
		std::cout << "�������������" << std::endl;
	else
		std::cout << "������������" << std::endl;
}

std::string Triangle::convertForFile() {
	std::stringstream ss;
	ss << "d" << std::endl;
	for (int i = 0; i < 3; i++)
		ss << nodes[i].x << " " << nodes[i].y << std::endl;
	return ss.str();
}

bool Triangle::isValid(std::vector<Point>& nodes) {
	return (Poly::isValid(nodes) && nodes.size() == 3) ? true : false;
}
Triangle* Triangle::createTriangle(std::vector<Point>& nodes) {
	sortInRightOrder(nodes);
	if (isValid(nodes))
		return new Triangle(nodes);
	return nullptr;
}
bool Triangle::isIsosceles() const {
	if (sides[0] == sides[1] || sides[1] == sides[2] || sides[2] == sides[0])
		return true;
	return false;
}
bool Triangle::isEquilateral() const {
	if (sides[0] == sides[1] && sides[1] == sides[2])
		return true;
	return false;
}
bool Triangle::isScalene() const {
	if (sides[0] != sides[1] && sides[0] != sides[2] && sides[1] != sides[2])
		return true;
	return false;
}
bool Triangle::isAcuteAngled() const {
	if (cos(angleBetween(a, b)) > 0 || cos(angleBetween(b, c)) > 0 || cos(angleBetween(a, c)) > 0)
		return true;
	return false;
}
bool Triangle::isObtuseAngled() const {
	if (cos(angleBetween(a, b)) < 0 || cos(angleBetween(b, c)) < 0 || cos(angleBetween(a, c)) < 0)
		return true;
	return false;
}
bool Triangle::isRightAngled() const {
	if (cos(angleBetween(a, b)) == 0 || cos(angleBetween(b, c)) == 0 || cos(angleBetween(a, c)) == 0)
		return true;
	return false;
}