#pragma once
#include "Tetragon.h"
#include <vector>
class Parallelogram : public Tetragon{
public:
	Parallelogram() : Tetragon(){}
	Parallelogram(const std::vector<Point>& v) : Tetragon(v){}
	virtual Point getCenterOfMass() const override;
	virtual double getPerimeter() const override;
	virtual void toString() override;
	static bool isValid(std::vector<Point>& nodes);
	static Parallelogram* createParallelogram(std::vector<Point>& nodes);
	virtual std::string convertForFile() override;
};