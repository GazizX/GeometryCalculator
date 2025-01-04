#include "inputFunctions.h"

using namespace std;
void inputChar(char& ans) {
	cin >> ans;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "������������ ����, ������� ������ �� ������������ ����: ";
		cin >> ans;
	}
	cout << endl;
}

void inputDouble(double& param) {
	cin >> param;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "������������ ����, ������� �����: ";
		cin >> param;
	}
	cout << endl;
}

void inputFloat(float& param) {
	cin >> param;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "������������ ����, ������� �����: ";
		cin >> param;
	}
	cout << endl;
}

void inputInt(int& param) {
	cin >> param;
	while (cin.fail() || param <= 0 || cin.get() == '.') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "������������ ����, ������� ����������� �����: ";
		cin >> param;
	}
	cout << endl;
}

Circle* inputCircle() {
	double radius;
	Point center;
	cout << "������� ������ �����: ";
	inputDouble(radius);
	cout << "������� ���������� ������ �����: " << endl;
	center = *inputPoint();
	return Circle::createCircle(radius, center);
}

Point* inputPoint() {
	float x, y;
	cout << "������� ���������� x: ";
	inputFloat(x);
	cout << "������� ���������� y: ";
	inputFloat(y);
	return new Point(x, y);
}
Poly* inputPoly() {
	int n;
	vector<Point> v;
	cout << "������� ���������� ������: ";
	inputInt(n);
	for (int i = 0; i < n; i++) {
		v.push_back(*inputPoint());
	}
	return Poly::createPoly(v);
}
Tetragon* inputTetragon() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Tetragon::createTetragon(v);
}
Triangle* inputTriangle() {
	vector<Point> v;
	for (int i = 0; i < 3; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Triangle::createTriangle(v);
}
Rect* inputRect() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Rect::createRect(v);
}
Line* inputLine() {
	Point a, b;
	cout << "����� 1" << endl;
	a = *inputPoint();
	cout << "����� 2" << endl;
	b = *inputPoint();
	return Line::createLine(a, b);
}
Rhomb* inputRhomb() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Rhomb::createRhomb(v);
}
Square* inputSquare() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Square::createSquare(v);
}
Parallelogram* inputParallelogram() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Parallelogram::createParallelogram(v);
}
Trapezoid* inputTrapezoid() {
	vector<Point> v;
	for (int i = 0; i < 4; i++) {
		cout << "������� " << i + 1 << endl;
		v.push_back(*inputPoint());
	}
	return Trapezoid::createTrapezoid(v);
}

