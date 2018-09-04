#include<iostream>
using namespace std;

class Point {
public:
    Point(int xx = 0,int yy = 0);
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    void print();
    void moveRight(int offset);
    void moveDown(int offset);

private:
    int x;
    int y;
};

int main() {
    int x, y;
    cout << "Please input a point: ";
    cin >> x >> y;
    Point p1(x,y); // Form Point1
    cout << "Point p1: ";
    p1.print();
    cout << endl;
    Point p2(x * 2, y * 2); //Form Point2
    cout << "Point p2: ";
    p2.print();
    cout << endl;
    p1.moveRight(10);
    cout << "After moving right, p1: ";
    p1.print();
    cout << endl;
    p2.moveDown(-10); // Negative means moving up
    cout << "After moving down, p2: ";
    p2.print();
    cout << endl;
    return 0;
}

void Point::print() {
    cout << "(" << x << "," << y << ")";
    return;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

void Point::moveRight(int offset) {
    x += offset;
    return;
}

void Point::moveDown(int offset) {
    y += offset;
    return;
}

Point::Point(int xx, int yy) {
    x = xx;
    y = yy;
}
