#include "Rectangle.h"

int Rectangle::m_count = 0;

Rectangle::Rectangle(double left, double top, double width, double height, int color1) :point1(left, top), point2(left + width, top + height) {
	++m_count;
	setColor(color1);
}
int Rectangle::getColor()const {
	return color;
}
Point& Rectangle::getTopLeftPoint() {
	return point1;
}
Point& Rectangle::getBottomRightPoint() {
	return point2;
}
void Rectangle::setColor(int color1) {
	color = color1;
}
bool Rectangle::contains(const Point& p) {
	if (p.getX() > point2.getX() || p.getX() < point1.getX())
		return false;
	if (p.getY() > point2.getY() || p.getY() < point1.getY())
		return false;
	return true;
}
void Rectangle::moveRect(double deltaLeft, double deltaTop) {
	point1.setX(point1.getX() - deltaLeft);
	point1.setY(point1.getY() + deltaTop);
	point2.setX(point1.getX() - deltaLeft);
	point2.setY(point1.getY() + deltaTop);
}
void Rectangle::scaleRect(double rectWidth, double rectHeight)
{
	double currWidth = point2.getX() - point1.getX();
	point1.setScaleX(rectWidth / currWidth);
	point2.setScaleX(rectWidth / currWidth);

	double currHeight = point1.getY() -point2.getY();
	point1.setScaleY(rectHeight / currHeight);
	point2.setScaleY(rectHeight / currHeight);
}
