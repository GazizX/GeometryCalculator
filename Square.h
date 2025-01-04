#pragma once
#include "MyRect.h"
#include "Rhomb.h"
class Square : public Rect, public Rhomb {
public:
	Square(std::vector<Point> v) : Parallelogram(v) {}
	void toString();
	static bool isValid(std::vector<Point>& nodes);
	static Square* createSquare(std::vector<Point>& nodes);
	std::string convertForFile() override;
};