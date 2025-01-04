#pragma once
#include "Circle.h"
#include "Poly.h"
#include "Line.h"
#include "Tetragon.h"
#include "Parallelogram.h"
#include "MyRect.h"
#include "Rhomb.h"
#include "Square.h"
#include "Figure.h"
#include "Triangle.h"
#include "Trapezoid.h"
void inputChar(char& ans);
void inputDouble(double& param);
void inputFloat(float& param);
void inputInt(int& param);
Circle* inputCircle();
Point* inputPoint();
Poly* inputPoly();
Tetragon* inputTetragon();
Triangle* inputTriangle();
Rect* inputRect();
Line* inputLine();
Rhomb* inputRhomb();
Square* inputSquare();
Parallelogram* inputParallelogram();
Trapezoid* inputTrapezoid();
template<class T>
void inputInVector(std::vector<T>& v, T& ptr) {
	if (!ptr)
		std::cout << "Некорректный ввод, попробуйте снова" << std::endl;
	else {
		v.push_back(ptr);
		std::cout << "Успешный ввод!" << std::endl;
	}
}
