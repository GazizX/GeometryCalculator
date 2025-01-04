#pragma once
#include "Poly.h"
#include "Line.h"
class Triangle : public Poly {
	Line a;
	Line b;
	Line c;
public:
	Triangle(std::vector<Point> v);
	void toString() override;
	static bool isValid(std::vector<Point>& nodes);
	static Triangle* createTriangle(std::vector<Point>& nodes);
	bool isIsosceles() const;
	bool isEquilateral() const;
	bool isScalene() const;
	bool isAcuteAngled() const;
	bool isObtuseAngled() const;
	bool isRightAngled() const;
	std::string convertForFile() override;
};