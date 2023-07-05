#pragma once
#ifndef _POINT
#define _POINT

using namespace std;

class Point
{
private:
	double x, y;
	double scaleX, scaleY;
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

