#include "allShapes.h"
#include "Circle.h"	
#include "Square.h"
allShapes::allShapes() :m_arr(nullptr) {
	m_size = 0;
}
allShapes::allShapes(const allShapes& other) {
	m_arr = new Shape * [other.m_size];
	for (int i = 0; i < other.m_size; i++)
	{
		if (typeid(*other.m_arr[i]) == typeid(Circle))
			m_arr[i] = new Circle(*((Circle*)other.m_arr[i]));
		else if (typeid(*other.m_arr[i]) == typeid(Quad))
			m_arr[i] = new Quad(*((Quad*)other.m_arr[i]));
		else if (typeid(*other.m_arr[i]) == typeid(Square))
			m_arr[i] = new Square(*((Square*)other.m_arr[i]));
	}
	m_size = other.m_size;
}
allShapes::~allShapes() {
	if (m_arr)
	{
		for (int i = 0; i < m_size; i++)
		{
			delete m_arr[i];
		}
		delete[] m_arr;
	}
}
int allShapes::getSize() const {
	return m_size;
}
void allShapes::addShape(Shape* newShape) {
	Shape** newarr = new Shape * [m_size + 1];
	for (int i = 0; i < m_size; i++)
	{
		{
			if (typeid(*m_arr[i]) == typeid(Circle))
				newarr[i] = new Circle(*((Circle*)m_arr[i]));
			else if (typeid(*m_arr[i]) == typeid(Quad))
				newarr[i] = new Quad(*((Quad*)m_arr[i]));
			else if (typeid(*m_arr[i]) == typeid(Square))
				newarr[i] = new Square(*((Square*)m_arr[i]));
		}
	}
	if (typeid(*newShape) == typeid(Circle))
		newarr[m_size] = new Circle(*((Circle*)newShape));
	else if (typeid(*newShape) == typeid(Quad))
		newarr[m_size] = new Quad(*((Quad*)newShape));
	else if (typeid(*newShape) == typeid(Square))
		newarr[m_size] = new Square(*((Square*)newShape));
	m_size = m_size + 1;
	delete[] m_arr;
	m_arr = newarr;
}
void allShapes::removeShape(int index) {
	if (index<0 || index>m_size)
		return;
	if (m_size == 1)
	{
		delete m_arr[0];
		delete[] m_arr;
		m_size = 0;
	}
	Shape** temp = new Shape * [m_size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = m_arr[i];
	}
	for (int t = index + 1; t < m_size; t++)
	{
		temp[t - 1] = m_arr[t];
	}
	m_size = m_size - 1;
	delete m_arr;
	m_arr = temp;
}
int allShapes::totalArea() const {
	double sum = 0;
	for (int i = 0; i < m_size; i++)
	{
		sum = sum + m_arr[i]->calcArea();
	}
	return sum;
}
int allShapes::totalPerimeter() const {
	double sum = 0;
	for (int i = 0; i < m_size; i++)
	{
		sum = sum + m_arr[i]->calcPerimeter();
	}
	return sum;
}
int allShapes::totalCircleArea() const {
	double sum = 0;
	for (int i = 0; i < m_size; i++)
	{
		if(typeid(*m_arr[i])==typeid(Circle))
			sum = sum + m_arr[i]->calcArea();
	}
	return sum;
}
int allShapes:: totalSquarePerimeter() const {
	double sum = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_arr[i]) == typeid(Square))
			sum = sum + m_arr[i]->calcPerimeter();
	}
	return sum;
}
const allShapes& allShapes:: operator+=(Shape* newS) {
	addShape(newS);
	return *this;
}
Shape* allShapes::operator[](int ind) const {
	for (int i = 0; i < m_size; i++)
	{
		if (i == ind)
			return m_arr[i];
	}
}
allShapes allShapes::operator+(const allShapes& other) const
{
	allShapes newAll;
	for (int i = 0; i < m_size; i++)
		newAll.addShape((*this)[i]);

	for (int i = 0; i < other.m_size; i++)
		newAll.addShape(other[i]);

	return newAll;
}
allShapes::operator int() const
{
	return m_size;
}