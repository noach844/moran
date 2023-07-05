#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include <typeinfo> 
#include <string.h>
using namespace std;


class Shape {
public:
    virtual ~Shape() {}
    virtual void save(ofstream& out) = 0;
    virtual void saveType(ofstream& out) = 0;
};

class Point:public Shape {
public:
    int x;
    int y;
    Point(int m_x = 0,int  m_y = 0) {
        x = m_x;
        y = m_y;
    }
    Point(Point& p) {
        x = p.x;
        y = p.y;
    }
    virtual ~Point() {
    }
    virtual void save(ofstream& out) {
        out.write((char*)&x, sizeof(x));
        out.write((char*)&y, sizeof(y));
    }
    Point(ifstream& in) {
        in.read((char*)&x, sizeof(x));
        in.read((char*)&y, sizeof(y));
        x = 0;
        y = 0;
    }
    virtual void saveType(ofstream& out) {
        out.write("P", 1);
    }

};

class Line : public Point {
public:
    Point from;
    Point to;
    Line(int x_from = 0, int y_from = 0, int x_to = 0, int y_to = 0): from(x_from,y_from), to(x_to,y_to) {
    }
    Line(Point p1, Point p2): from(p1), to(p2) {
    }
    Line(Line& l): from(l.from), to(l.to) {
    }
    virtual ~Line() {}
    Line(ifstream& in) {
        from = Point(in);
        to = Point(in);
    }
    virtual void save(ofstream& out) {
        from.save(out);
        to.save(out);
    }
    virtual void saveType(ofstream& out) {
        out.write("L", 1);
    }
};

class Area : public Line {
public:
    Line l1;
    Line l2;
    Area(int x_from = 0, int y_from = 0, int x_to = 0, int y_to = 0, int x1_from = 0, int y1_from = 0, int x1_to = 0, int y1_to = 0):
        l1(x_from, y_from, x_to, y_to),
        l2(x1_from, y1_from, x1_to, y1_to)
    {}
    Area(Line line1, Line line2): l1(line1), l2(line2){}
    virtual ~Area() {}
    Area(ifstream& in) {
        l1 = Line(in);
        l2 = Line(in);
    }

    virtual void save(ofstream& out) {
        l1.save(out);
        l2.save(out);
    }
    virtual void saveType(ofstream& out) {
        out.write("A", 1);
    }
};

void save(Shape** shapes, int size, const char* fileName) {
    ofstream out(fileName);
    out.write((char*)&size, sizeof(size));
    for (int i = 0; i < size; i++) {
        shapes[i]->saveType(out);
        shapes[i]->save(out);
    }
    out.close();
}

Shape** load(const char* fileName) {
    ifstream in(fileName);
    int size;
    in.read((char*)&size, sizeof(size));
    Shape** shapes = new Shape * [size];
    for (int i = 0; i < size; i++) {
        char type;
        in.read(&type, 1); // P, L, or A
        Shape* s;
        switch (type)
        {
        case 'P': s = new Point(in); break;
        case 'L': s = new Line(in); break;
        case 'A': s = new Area(in); break;
        }
        shapes[i] = s;
    }
    in.close();
    return shapes;
}

#endif /* SRC_Q2_H_ */
