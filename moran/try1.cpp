//#include <iostream>
//using namespace std;
//class Cost {
//	int value;
//public:
//	void setvalue(int value) {
//		this->value = value;
//	}
//	Cost& increase() {
//		value++;
//		return *this;
//	}
//	int getvalue() {
//		return value;
//	}
//};
//void main() {
//	Cost c;
//	c.setvalue(20);
//	c.increase().increase().increase();
//	cout << c.getvalue();
//}
//class Point {
//	int m_x;
//	int m_y;
//public:
//	Point() {
//		m_x = 0;
//		m_y = 0;
//	}
//	Point(int x, int y, bool printme = true) {
//		m_x = x;
//		m_y = y;
//		if (printme)
//			Print();
//	}
//	void Print() {
//		cout << "x=" << m_x << ",y=" << m_y << endl;
//	}
//};
//void Main() {
//	Point p1;
//	Point p2(3, 4);
//	Point p3(5, 6, false);
//}