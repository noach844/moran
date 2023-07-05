#include "Point.h"

Point::Point(double x, double y) {
    this->_x = x;
    this->_y = y;
}

double Point::getX() const {
    return this->_x * this->_scaleX;
}

double Point::getY() const {
    return this->_y * this->_scaleY;
}

void Point::setX(double x) {
    this->_x = x;
}

void Point::setY(double y) {
    this->_y = y;
}

void Point::setScaleX(double scaleX) {
    this->_scaleX = scaleX;
}

void Point::setScaleY(double scaleY) {
    this->_scaleY = scaleY;
}