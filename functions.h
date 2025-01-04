#pragma once
#include "Point.h"
#include "Circle.h"
#include "Poly.h"
#include "Line.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
double lengthOfSide(Point a, Point b);
double angleFromCenter(const Point& center, const Point& p);
void printMainMenu();
void printSortMenu();
void printDeleteMenu();
void printOutputMenu();
void printFiguresMenu();
void inputChar(char& ans);
bool areInLine(Point& a, Point& b, Point& c);
void sortInRightOrder(std::vector<Point>& nodes);
double vectorProduct(const Point& a, const Point& b, const Point& c);
bool isInFigure(Point& a, Poly* p);
bool isInFigure(Point& a, Circle* c);
sf::Vector2f convertToSFML(const Point& point);
void drawGrid(sf::RenderWindow& window, const sf::View& view, float cellSize);
void drawSurface(std::vector<Figure*>& v, std::vector<Line*>& l, std::vector<Point*>& p);