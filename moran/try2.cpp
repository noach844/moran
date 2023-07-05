//#include <iostream>
//using namespace std;
//
//class Point {
//	int m_x;
//	int m_y;
//public:
//	Point() {
//		m_x = 0;
//		m_y = 0;
//	}
//	void Print() {
//		cout << "x=" << m_x << ",y=" << m_y << endl;
//	}
//	void set(int x, int y) {
//		m_x = x;
//		m_y = y;
//	}
//};
//class Polygon {
//	int size;
//	Point* array;
//public:
//	Polygon() :size(0), array(NULL) {}
//	Polygon(int asize);
//	~Polygon();
//	void print (){/*...*/}
//};
//
//Polygon::Polygon(int asize) :size(asize) {
//	array = new Point[size];
//	int x, y;
//	for (int i = 0; i < size; i++) {
//		cout << "enter point" << (i + 1) << endl;
//		cin >> x >> y;
//		array[i].set(x, y);
//	}
//};
//Polygon::~Polygon() {
//	if (array != NULL)
//		delete[]array;
//}
//
//void main() {
//	Polygon poly1;
//	Polygon poly2(5);
//}