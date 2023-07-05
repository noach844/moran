#include "point.h"
Point::Point(double x1, double y1) {
	x = x1;
	y = y1;
	scaleX = 1;
	scaleY = 1;
}
double Point::getX() const {
	return  x * scaleX;
}
double Point::getY() const {
	return  y * scaleY;
}
void Point::setX(double x2) {
	x = x2;
}
void Point::setY(double y2) {
	y = y2;
}
void Point:: setScaleX(double scalex1) {
	scaleX = scalex1;
}
void Point::setScaleY(double scaley1) {
	scaleY = scaley1;
}