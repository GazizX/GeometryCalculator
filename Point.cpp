#include "Point.h"
#include <sstream>
std::ostream& operator << (std::ostream& os, const Point& p)
{
    return os << "(" << p.x << "; " << p.y << ")";
}
bool Point::operator == (const Point& other) {
    return (x == other.x && y == other.y) ? true : false;
}
std::string Point::convertForFile() {
	std::stringstream ss;
	ss << "p" << std::endl;
	ss << x << " " << y << std::endl;
	return ss.str();
}
void Point::drawFigure(sf::RenderWindow& window, int width, int height) {
	float radius = 0.1;
	sf::CircleShape point(radius);
	point.setPosition(x, y);
	point.setFillColor(sf::Color::Black);
	point.setOrigin(radius, radius);
	window.draw(point);
}