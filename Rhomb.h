#pragma once
#include "Parallelogram.h"
class Rhomb : virtual public Parallelogram {
public:
	Rhomb(){}
	Rhomb(std::vector<Point> v) : Parallelogram(v) {}
	virtual double getPerimeter() const;
	virtual void toString();
	static bool isValid(std::vector<Point>& nodes);
	static Rhomb* createRhomb(std::vector<Point>& nodes);
	virtual std::string convertForFile() override;
};