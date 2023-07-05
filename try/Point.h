#ifndef _POINT
#define _POINT
#pragma once
using namespace std;

class Point
{
private:
	double _x;
	double _y;
	double _scaleX = 1;
	double _scaleY = 1;

public:
	Point(double x, double y);

public:
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void setScaleX(double scaleX);
	void setScaleY(double scaleY);
};

#endif