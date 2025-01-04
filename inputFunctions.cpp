#include "inputFunctions.h"

using namespace std;
void inputChar(char& ans) {
	cin >> ans;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Некорректный ввод, введите символ из предложенных выше: ";
		cin >> ans;
	}
	cout << endl;
}

void inputDouble(double& param) {
	cin >> param;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Некорректный ввод, введите число: ";
		cin >> param;
	}
	cout << endl;
}

void inputFloat(float& param) {
	cin >> param;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Некорректный ввод, введите число: ";
		cin >> param;
	}
	cout << endl;
}

void inputInt(int& param) {
	cin >> param;
	while (cin.fail() || param <= 0 || cin.get() == '.') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Некорректный ввод, введите натуральное число: ";
		cin >> param;
	}
	cout << endl;
}

Circle* inputCircle() {
	double radius;
	Point center;
	cout << "Введите радиус круга: ";
	inputDouble(radius);
	cout << "Введите координаты центра круга: " << endl;
	center = *inputPoint();
	return Circle::createCircle(radius, center);
}

Point* inputPoint() {
	float x, y;
	cout << "Введите координату x: ";
	inputFloat(x);
	cout << "Введите координату y: ";
	inputFloat(y);
	return new Point(x, y);
}
Poly* inputPoly() {
	int n;
	vector<Point> v;
	cout << "Введите количество вершин: ";
	inputInt(n);
	for (int i = 0; i < n; i++) {
		v.push_back(*inputPoint());
	}
	return Poly::createPoly(v);
}
Tetragon* inputTetragon() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Tetragon::createTetragon(v);
}
Triangle* inputTriangle() {
	vector<Point> v;
	for (int i = 0; i < 3; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Triangle::createTriangle(v);
}
Rect* inputRect() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Rect::createRect(v);
}
Line* inputLine() {
	Point a, b;
	cout << "Точка 1" << endl;
	a = *inputPoint();
	cout << "Точка 2" << endl;
	b = *inputPoint();
	return Line::createLine(a, b);
}
Rhomb* inputRhomb() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Rhomb::createRhomb(v);
}
Square* inputSquare() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Square::createSquare(v);
}
Parallelogram* inputParallelogram() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Parallelogram::createParallelogram(v);
}
Trapezoid* inputTrapezoid() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Trapezoid::createTrapezoid(v);
}

