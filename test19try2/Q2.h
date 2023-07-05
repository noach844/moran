#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include <typeinfo>
using namespace std;


class Shape {
public:
    virtual ~Shape() {}
    virtual void savenum (ofstream& out){}
    virtual void savetype (ofstream& out){}
};

class Point: public Shape {
public:
    int x;
    int y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int m_x, int m_y) {
        x = m_x;
        y = m_y;
    }
    Point(Point& other):x(other.x), y(other.y){}
    virtual void savenum(ofstream& out) {
        out.write((char*)&x, sizeof(x));
        out.write((char*)&y, sizeof(y));
    }
    virtual void savetype(ofstream& out) {
        out.write("P",1);
    }
};

class Line : public Point {
public:
    Point from;
    Point to;
    Line() :Point() {}
    Line(int x1, int y1, int x2, int y2) :from(x1, y1), to(x2, y2) {}
    Line(Point& f, Point& t):from(f), to(t){}
    virtual void savenum(ofstream& out) {
        from.savenum(out);
        to.savenum(out);
    }
    virtual void savetype(ofstream& out) {
        out.write("L",1);
    }


};

class Area: public Line {
public:
    Line l1;
    Line l2;
    Area():Line(){}
    Area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4):
        l1(x1, y1, x2, y2), l2(x3, y3, x4, y4){}
    Area(Line line1, Line line2):l1(line1), l2(line2){}
    virtual void savenum(ofstream& out) {
        l1.savenum(out);
        l2.savenum(out);
    }
    virtual void savetype(ofstream& out) {
        out.write("A", 2);
    }
};

void save(Shape** shapes, int size, const char* fileName) {
    ofstream out;
    out.open(fileName, ios::binary | ios::out);
    out.write((char*)&size, sizeof(size));
    for (int i = 0; i < size; i++)
    {
        if (typeid(*shapes[i]) == typeid(Point))
        {
            ((Point*)shapes[i])->savetype(out);
            ((Point*)shapes[i])->savenum(out);
        }
        if (typeid(*shapes[i]) == typeid(Line))
        {
            ((Line*)shapes[i])->savetype(out);
            ((Line*)shapes[i])->savenum(out);
        }
        if (typeid(*shapes[i]) == typeid(Area))
        {
            ((Area*)shapes[i])->savetype(out);
            ((Area*)shapes[i])->savenum(out);
        }
    }
    out.close();
}

Shape** load(const char* fileName) {
    ifstream in;
    int size;
    in.open(fileName, ios::binary | ios::in);
    in.read((char*)&size, sizeof(size));
    Shape** temp = new Shape * [size];
    for (int i = 0; i < size; i++)
    {
        char t;
        in.read((char*)&t, sizeof(t));
        if (t=='P')
        {
            int x, y;
            in.read((char*)&x, sizeof(x));
            in.read((char*)&y, sizeof(y));
            temp[i] = new Point(x,y);
        }
        if (t == 'L')
        {
            int x1, y1, x2, y2;
            in.read((char*)&x1, sizeof(x1));
            in.read((char*)&y1, sizeof(y1));
            in.read((char*)&x2, sizeof(x2));
            in.read((char*)&y2, sizeof(y2));
            temp[i] = new Line(x1, y1, x2, y2);
        }
        if (t == 'A')
        {
            int x1, y1, x2, y2, x3, y3, x4, y4;
            in.read((char*)&x1, sizeof(x1));
            in.read((char*)&y1, sizeof(y1));
            in.read((char*)&x2, sizeof(x2));
            in.read((char*)&y2, sizeof(y2));
            in.read((char*)&x3, sizeof(x3));
            in.read((char*)&y3, sizeof(y3));
            in.read((char*)&x4, sizeof(x4));
            in.read((char*)&y4, sizeof(y4));
            temp[i] = new Area(x1, y1, x2, y2, x3, y3, x4, y4);
        }
    }
    in.close();
    return temp;
}

#endif /* SRC_Q2_H_ */
