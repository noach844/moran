#include "Shape.h"
int Shape::s_totalNumOfShapes = 0;
Shape::Shape(const char* sn):m_shapeName(nullptr) {
	setName(sn);
	setCenter(Point());
	s_totalNumOfShapes++;
}
Shape::Shape(const Shape& other):m_shapeName(nullptr) {
	setName(other.m_shapeName);
	setCenter(other.m_centerPoint);
	s_totalNumOfShapes++;
}
Shape:: ~Shape() {
	if (m_shapeName)
		delete m_shapeName;
	s_totalNumOfShapes--;
}
void Shape::setName(const char* name) {
	if (m_shapeName)
		delete m_shapeName;
	m_shapeName = new char[strlen(name) + 1];
	strcpy(m_shapeName, name);
}
void Shape::setCenter(const Point& p) {
	m_centerPoint.setPoint(p);
}
const char* Shape::getName() const {
	return m_shapeName;
}
Point Shape::getCenter() const {
	return m_centerPoint;
}
void Shape::setShape(const char* sn, const Point& other) {
	setName(sn);
	setCenter(other);
}
int Shape::numOfShapes() {
	return s_totalNumOfShapes;
}
const Shape& Shape::operator=(const Shape& other) {
	Shape* newshape(this);
	newshape->setCenter(other.m_centerPoint);
	newshape->setName(other.m_shapeName);
	return *newshape;
}