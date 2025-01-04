#include "functions.h"
#include <algorithm>
#include <cmath>
using namespace std;
double lengthOfSide(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double angleFromCenter(const Point& center, const Point& p) {
	return std::atan2(p.y - center.y, p.x - center.x);
}

void sortInRightOrder(std::vector<Point>& nodes) {
	float x_center = 0;
	float y_center = 0;
	for (int i = 0; i < nodes.size(); i++) {
		x_center += nodes[i].x;
		y_center += nodes[i].y;
	}
	Point c(x_center / nodes.size(), y_center / nodes.size());
	std::sort(nodes.begin(), nodes.end(), [&c](const Point& p1, const Point& p2) {
		return angleFromCenter(c, p1) < angleFromCenter(c, p2);
		});
}

void printMainMenu() {
	cout << "---------------------------------- Главное Меню ----------------------------------" << endl
		<< "a - Ввод фигуры" << endl
		<< "b - Вывод данных фигуры (рассчет площади, периметра, центра масс, свойства фигуры)" << endl
		<< "x - Удаление фигуры" << endl
		<< "c - Рассчет расстояний между фигурами (между центрами масс)" << endl
		<< "d - Ранжирование фигур по характеристикам (площадь/периметр)" << endl
		<< "p - Проверка точки на принадлежность той или иной фигуре" << endl
		<< "f - Чтение из файла" << endl
		<< "o - Запись в файл" << endl
		<< "v - Визуализация всех фигур" << endl
		<< "e - Выход из программы" << endl;
}
void printDeleteMenu() {
	cout << "---------------------------------- Удаление фигуры ----------------------------------" << endl
		<< "a - Удалить фигуру" << endl
		<< "b - Удалить прямую" << endl
		<< "с - Удалить точку" << endl;
}
void printSortMenu() {
	cout << "---------------------------------- Сортировка ----------------------------------" << endl
		<< "a - Сортировка по площади(возрастающая)" << endl
		<< "b - Сортировка по площади(убывающая)" << endl
		<< "c - Сортировка по периметру(возрастающая)" << endl
		<< "d - Сортировка по периметру(убывающая)" << endl;
}
void printOutputMenu() {
	cout << "---------------------------------- Запись в файл ----------------------------------" << endl
		<< "a - Один элемент (фигура)" << endl
		<< "b - Один элемент (прямая)" << endl
		<< "c - Один элемент (точка)" << endl
		<< "d - Несколько элементов (фигуры)" << endl
		<< "e - Несколько элементов (прямые)" << endl
		<< "f - Несколько элементов (точки)" << endl
		<< "g - Все элементы" << endl;
}
void printFiguresMenu() {
	cout << "------------------- Выбор фигуры -------------------" << endl
		<< "a - Круг" << endl
		<< "b - Многоугольник" << endl
		<< "c - Четырехугольник" << endl
		<< "d - Треугольник" << endl
		<< "t - Трапеция" << endl
		<< "f - Параллелограм" << endl
		<< "g - Прямоугольник" << endl
		<< "r - Ромб" << endl
		<< "q - Квадрат" << endl
		<< "p - Точка" << endl
		<< "l - Прямая" << endl;
}

bool areInLine(Point& a, Point& b, Point& c) {
	return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0;
}

double vectorProduct(const Point& a, const Point& b,const Point& c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isInFigure(Point& a, Poly* p) {
	bool flag = false;
	std::vector<Point> nodes = p->getNodes();
	float first_x, first_y, second_x, second_y;
	first_x = nodes[0].x;
	first_y = nodes[0].y;
	for (int i = 0; i < nodes.size() + 1; i++) {
		second_x = nodes[i % nodes.size()].x;
		second_y = nodes[i % nodes.size()].y;
		if (a.y > min(first_y, second_y)) {
			if (a.y <= max(first_y, second_y)) {
				if (a.x <= max(first_x, second_x)) {
					if (first_y != second_y) {
						double xinters = (a.y - first_y) * (second_x - first_x) / (second_y - first_y) + first_x;
						if (first_x == second_x || a.x <= xinters) {
							flag = !flag;
						}
					}

				}
			}
		}
		first_x = second_x;
		first_y = second_y;
	}
	return flag;
}

bool isInFigure(Point& a, Circle* c) {
	if (lengthOfSide(a, c->getCenterOfMass()) <= c->getRadius())
		return true;
	return false;
}

sf::Vector2f convertToSFML(const Point& point) {
	return { point.x, point.y };
}


void drawGrid(sf::RenderWindow& window, const sf::View& view, float cellSize) {
	sf::Vector2f viewCenter = view.getCenter();
	sf::Vector2f viewSize = view.getSize();

	float left = viewCenter.x - viewSize.x / 2;
	float right = viewCenter.x + viewSize.x / 2;
	float bottom = viewCenter.y - viewSize.y / 2;
	float top = viewCenter.y + viewSize.y / 2;

	float startX = std::floor(left / cellSize) * cellSize;
	float endX = std::ceil(right / cellSize) * cellSize;
	float startY = std::floor(top / cellSize) * cellSize;
	float endY = std::ceil(bottom / cellSize) * cellSize;
	sf::VertexArray gridLines(sf::Lines);
	for (float y = startY; y <= endY; y += cellSize) {
		gridLines.append(sf::Vertex(sf::Vector2f(left, y), sf::Color(200, 200, 200, 128)));
		gridLines.append(sf::Vertex(sf::Vector2f(right, y), sf::Color(200, 200, 200, 128)));
	}
	for (float x = startX; x <= endX; x += cellSize) {
		gridLines.append(sf::Vertex(sf::Vector2f(x, top), sf::Color(200, 200, 200, 128)));
		gridLines.append(sf::Vertex(sf::Vector2f(x, bottom), sf::Color(200, 200, 200, 128)));
	}

	sf::Vertex xAxis[] = {
		sf::Vertex(sf::Vector2f(left, 0), sf::Color::Black),
		sf::Vertex(sf::Vector2f(right, 0), sf::Color::Black)
	};
	sf::Vertex yAxis[] = {
		sf::Vertex(sf::Vector2f(0, top), sf::Color::Black),
		sf::Vertex(sf::Vector2f(0, bottom), sf::Color::Black)
	};
	window.draw(xAxis, 2, sf::Lines);
	window.draw(yAxis, 2, sf::Lines);
	window.draw(gridLines);
}

void drawSurface(std::vector<Figure*>& v, std::vector<Line*>& l, std::vector<Point*>& p) {
	int width = 600;
	int height = 600;
	float zoomLevel = 25.0f;
	float scaling = 1.1f;
	sf::RenderWindow window(sf::VideoMode(width, height), "Geometry Calcaulator");
	sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(width / zoomLevel, -height / zoomLevel));
	window.setView(view);
	bool isMousePressed = false;
	sf::Vector2i mouseStartPos;
	sf::Vector2f viewStartPos;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				isMousePressed = true;
				mouseStartPos = sf::Mouse::getPosition(window);
				viewStartPos = view.getCenter();
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				isMousePressed = false;
			}
			if (event.type == sf::Event::MouseWheelMoved) {
				if (event.mouseWheel.delta > 0) {
					zoomLevel *= scaling;
				}
				else if (event.mouseWheel.delta < 0) {
					zoomLevel /= scaling;
				}
				view.setSize(width / zoomLevel, -height / zoomLevel);
			}
		}
		if (isMousePressed) {
			sf::Vector2i mouseCurrentPos = sf::Mouse::getPosition(window);
			sf::Vector2f offset = sf::Vector2f(
				(mouseStartPos.x - mouseCurrentPos.x) / zoomLevel,
				(mouseCurrentPos.y - mouseStartPos.y) / zoomLevel
			);
			view.setCenter(viewStartPos + offset);
		}
		window.setView(view);
		window.clear(sf::Color::White);
		drawGrid(window, view, 25.f / zoomLevel);
		for_each(v.begin(), v.end(), [&](Figure* fig) {
			fig->drawFigure(window, width, height);
			});
		for_each(l.begin(), l.end(), [&](Line* line) {
			line->drawFigure(window, width, height);
			});
		for_each(p.begin(), p.end(), [&](Point* point) {
			point->drawFigure(window, width, height);
			});

		window.display();
	}
}
