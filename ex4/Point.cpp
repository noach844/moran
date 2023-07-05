#include "Point.h"
Point::Point(int x, int y ) {
	m_x = x;
	m_y = y;
}
Point::Point(const Point& other) {
	m_x = other.m_x;
	m_y = other.m_y;
}
Point::~Point() {
}
int Point::getX() const {
	return m_x;
}
int Point::getY() const {
	return m_y;
}
void Point::setX(int x) {
	m_x = x;
}
void Point::setY(int y) {
	m_y = y;
}
void Point::setPoint(int x, int y) {
	m_x = x;
	m_y = y;
}
void Point::setPoint(const Point& other) {
	m_x = other.m_x;
	m_y = other.m_y;
}
bool Point::operator==(const Point& other) const {
	if (m_x == other.m_x && m_y == other.m_y)
		return true;
	return false;
}
bool Point:: operator!=(const Point& other) const {
	if (m_x == other.m_x && m_y == other.m_y)
		return false;
	return true;
}
Point Point::operator+ (int num) const {
	Point newpoint(*this);
	newpoint.setX(m_x + num);
	newpoint.setY(m_y + num);
	return newpoint;
}
const Point& Point::operator+=(int num) {
	setX(m_x + num);
	setY(m_y + num);
	return *this;
}
Point::operator int() const {
	return m_x + m_y;
}
Point Point:: operator+(const Point& other) const {
	Point* newpoint1 = new Point();
	newpoint1->setX(m_x + other.getX());
	newpoint1->setY(m_y + other.getY());
	return *newpoint1;
}
Point Point:: operator++(int) {
	setX(m_x + 1);
	setY(m_y + 1);
	return *this;
}
const Point& Point::operator++() {
	setX(m_x + 1);
	setY(m_y + 1);
	return *this;
}
Point operator*(int num, const Point& other) {
	Point newpoint2;
	newpoint2.setX(other.m_x * num);
	newpoint2.setY(other.m_y * num);
	return newpoint2;
}