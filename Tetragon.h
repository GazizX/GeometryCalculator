#pragma once
#include "Poly.h"
#include <vector>
class Tetragon : public Poly {
public:
	Tetragon(){}
	Tetragon(const std::vector<Point> v) : Poly(v) {} 
	virtual double getSquare() const override;
	virtual void toString() override;
	static bool isValid(std::vector<Point>& nodes);
	static Tetragon* createTetragon(std::vector<Point>& nodes);
	virtual std::string convertForFile() override;
};