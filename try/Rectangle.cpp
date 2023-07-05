#include "Rectangle.h"

int Rectangle::m_count = 0;

Rectangle::Rectangle(double left, double top, double width, double height, int color)
    : _bottomRight(left + width, top - height), _topLeft(left, top)
{
    this->color = color;
    ++m_count;
}
int Rectangle::getColor() const
{
    return color;
}

Point& Rectangle::getTopLeftPoint()
{
    return this->_topLeft;
}

Point& Rectangle::getBottomRightPoint()
{
    return this->_bottomRight;
}

void Rectangle::setColor(int color)
{
    this->color = color;
}

bool Rectangle::contains(const Point& p)
{
    bool xRange = this->_bottomRight.getX() >= p.getX() && this->_topLeft.getX() <= p.getX();
    bool yRange = this->_topLeft.getY() >= p.getY() && this->_bottomRight.getY() <= p.getY();

    return xRange && yRange;
}

void Rectangle::moveRect(double deltaLeft, double deltaTop)
{
    this->_bottomRight.setX(this->_bottomRight.getX() + deltaLeft);
    this->_bottomRight.setY(this->_bottomRight.getY() + deltaTop);
    this->_topLeft.setX(this->_topLeft.getX() + deltaLeft);
    this->_topLeft.setY(this->_topLeft.getY() + deltaTop);
}

void Rectangle::scaleRect(double rectWidth, double rectHeight)
{
    double currentScaleX = _bottomRight.getX() - _topLeft.getX();
    double currentScaleY = _topLeft.getY() - _bottomRight.getY();
    _topLeft.setScaleX(rectWidth / currentScaleX);
    _topLeft.setScaleY(rectHeight / currentScaleY);
    _bottomRight.setScaleX(rectWidth / currentScaleX);
    _bottomRight.setScaleY(rectHeight / currentScaleY);
}

//omer