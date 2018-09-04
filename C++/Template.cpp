#include <iostream>
#include <cmath>
#include "Array.h"
#include <algorithm>

using namespace std;

class Shape {
public:
    virtual double getCircumference() const = 0;
    virtual void getInfo() const = 0;
    bool operator> (Shape &shape2) {
        return this -> getCircumference() > shape2.getCircumference();
    }
};

class Circle: public Shape {
public:
    Circle(double r) {
        radius = r;
    };
    Circle()    {
        radius = 0;
    }
    Circle(const Circle& cir) {
        radius = cir.radius;
    };
    ~Circle(){};
    double getCircumference() const;
    void getInfo() const;
    void setRadius(int r) {
        radius = r;
    };
private:
    double radius;
};

class Rectangle: public Shape {
public:
    Rectangle(double Length, double Width) {
        length = Length;
        width = Width;
    };
    Rectangle() {
        length = 0;
        width = 0;
    }
    Rectangle(const Rectangle& rec) {
        length = rec.length;
        width = rec.width;
    }
    ~Rectangle(){};
    double getCircumference() const;
    void getInfo() const;
    void setLW(int l, int w) {
        length = l;
        width = w;
    }
private:
    double length;
    double width;
};

class RightTriangle: public Shape {
public:
    RightTriangle(double s1, double s2) {
        side1 = s1;
        side2 = s2;
    }
    RightTriangle(const RightTriangle& rtri) {
        side1 = rtri.side1;
        side2 = rtri.side2;
    }
    RightTriangle() {
        side1 = 0;
        side2 = 0;
    }
    ~RightTriangle(){};
    double getCircumference() const;
    void getInfo() const;
    void setSides(int s1, int s2) {
        side1 = s1;
        side2 = s2;
    }
private:
    double side1;
    double side2;
};

double Circle::getCircumference() const{
    return radius * radius * 3.1415;
}

double Rectangle::getCircumference() const{
    return (length + width) * 2;
}

double RightTriangle::getCircumference() const{
    return side1 + side2 + sqrt(side1 * side1 + side2 * side2);
}

void Circle::getInfo() const{
    cout << "圆， 半径 " << radius << "，周长 " << this->getCircumference() << endl;
}

void Rectangle::getInfo() const{
    cout << "长方形， 长 " << length << "，宽 " << width << "，周长 " << this->getCircumference() << endl;
}

void RightTriangle::getInfo() const{
    cout << "三角形， 直角边 " << side1 << "直角边 " << side2 << "，周长 " << this->getCircumference() << endl;
}

int main() {
    Array <Shape *> shapes(5);
    int pos = 0, sz;
    cout << "请输入至少五条信息：" << endl;
    while(1) {
        int choice = 0;
        if (pos == shapes.getSize()) shapes.resize(pos * 2);
        cout << "No." << pos + 1 << endl;
        cin >> choice;
        if(choice == -1)  break;
        else {
                /*Circle cir;
                Rectangle rec;
                RightTriangle rtri;*/
                if(choice == 1){
                    double radius = 0;
                    cout << "请输入半径：";
                    cin >> radius;
                    shapes[pos] = new Circle(radius);
                    pos++;
                }
                else if(choice == 2){
                    double length = 0, width = 0;
                    cout << ": 请输入长和宽：";
                    cin >> length >> width;
                    shapes[pos] = new Rectangle(length, width);
                    pos++;
                }
                else if(choice == 3){
                    double side1 = 0, side2 = 0;
                    cout << ": 请输入直角边长：";
                    cin >> side1 >> side2;
                    shapes[pos] = new RightTriangle(side1, side2);
                    pos++;
                }
                else {
                    cout << "请输入正确的数字" << endl;
                }
            }
        }
    sz = shapes.getSize() - 1;
    for(int i = 1; i < pos; i++) {
        Shape *temp = shapes[i];
        int posi = i;
        while(posi > 0 && *shapes[posi - 1] > *temp) {
            shapes[posi] = shapes[posi - 1];
            posi--;
        }
        shapes[posi] = temp;
    }
    for(int i = 0; i < pos; i++) {
        if(shapes[i] != NULL)
        shapes[i] -> getInfo();
    }
    delete *shapes;
    return 0;
}



