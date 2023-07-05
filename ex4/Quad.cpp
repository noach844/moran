#include "Quad.h"
Quad::Quad(double u, double d, double r, double l, const char* sn)
	: Shape(sn),
	m_up(u), m_down(d), m_right(r), m_left(l)
{
}
Quad::Quad(const Quad& other) : Shape(other) {
	m_up = other.m_up;
	m_down = other.m_down;
	m_right = other.m_right;
	m_left = other.m_left;
}
Quad::~Quad() {}
int Quad::calcArea() const {
	return (m_right * m_up);
}
int Quad::calcPerimeter() const {
	return (m_up + m_down + m_right + m_left);
}