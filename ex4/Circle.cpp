#include "Circle.h"
Circle::Circle(double r, const char* sn):Shape(sn) {
	setRadius(r);
}
Circle::Circle(const Circle& other): Shape(other.getName()) {
	setRadius(other.getRadius());
	setCenter(other.getCenter());
}
Circle:: ~Circle(){}
double Circle::getRadius() const {
	return m_radius;
}
void Circle::setRadius(double r) {
	m_radius = r;
}
int Circle::calcArea() const {
	int sum = PI * m_radius * m_radius;
	return sum;
}
int Circle::calcPerimeter() const {
	double sum1 = m_radius * 2 * PI;
	return sum1;
}
Circle operator+(int r, const Circle& other) {
	Circle newcircle(other);
	newcircle.setRadius(newcircle.getRadius() + r);
	return newcircle;
}
const Circle& Circle:: operator=(const Circle& other) {
	if (this != &other)
	{
		Shape::operator=(other);
		setRadius(other.m_radius);
	}
	return *this;
}
const Circle& Circle::operator=(const char* name)
{
	setName(name);
	return (*this);
}