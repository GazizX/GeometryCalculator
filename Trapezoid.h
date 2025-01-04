#pragma once
#include "Tetragon.h"
class Trapezoid : public Tetragon {
public:
	Trapezoid(std::vector<Point> v) : Tetragon(v) {}
	virtual void toString() override;
	static bool isValid(std::vector<Point>& nodes);
	static Trapezoid* createTrapezoid(std::vector<Point>& nodes);
	bool isRightAngled() const;
	bool isIsosceles() const;
	std::string convertForFile() override;
};