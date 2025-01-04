#pragma once
#include "Parallelogram.h"
class Rect : virtual public Parallelogram {
public:
	Rect() {}
	Rect(std::vector<Point> v) : Parallelogram(v) {}
	virtual double getSquare() const override;
	virtual void toString() override;
	static bool isValid(std::vector<Point>& nodes);
	static Rect* createRect(std::vector<Point>& nodes);
	virtual std::string convertForFile() override;
};