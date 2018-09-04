#include <iostream>
#include <cmath>
#include "Array.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class FileNotFoundException: public exception {
public:
    FileNotFoundException() {cout << "FNFE initiated." << endl;};
    void ErrorOpening(const string& str) {cout << str << endl;}
};

class Shape {
public:
    virtual double getCircumference() const = 0;
    virtual void getInfo() const = 0;
    bool operator> (Shape &shape2) {
        return this -> getCircumference() > shape2.getCircumference();
    };
    int classId;
    int price;
    void setPrice(int p) {price = p;};
};

class Circle: public Shape {
public:
    Circle(double r, int price): radius(r), price(price) {classId = 1; setPrice(price);};
    Circle()    {
        radius = 3;
        price = 1;
        classId = 1;
    }
    Circle(const Circle& cir) {
        radius = cir.radius;
        price = cir.price;
    };
    ~Circle(){};
    double getCircumference() const;
    void getInfo() const;
    void setRadius(int r) {
        radius = r;
    };
private:
    double radius;
    double price;
};

class Rectangle: public Shape {
public:
    Rectangle(double Length, double Width, int price): length(Length), width(Width), price(price) {classId = 2;};
    Rectangle() {
        length = 3;
        width = 3;
        price = 1;
        classId = 2;
    }
    Rectangle(const Rectangle& rec) {
        length = rec.length;
        width = rec.width;
        price = rec.price;
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
    double price;
};

class Square: public Rectangle {
public:
    Square(double side, int price): side(side), price(price) {classId = 4;};
    Square() {
        side = 3;
        price = 1;
        classId = 4;
    };
    ~Square(){};
    Square(const Square& square): side(square.side), price(square.price) {};
    double getCircumference() const;
    void getInfo() const;
    void setSide(int Side) {
        side = Side;
    }
private:
    double side;
    double price;
};

class RightTriangle: public Shape {
public:
    RightTriangle(double s1, double s2, int price): side1(s1), side2(s2), price(price) {classId = 3;};
    RightTriangle(const RightTriangle& rtri) {
        side1 = rtri.side1;
        side2 = rtri.side2;
        price = rtri.price;
    }
    RightTriangle() {
        side1 = 3;
        side2 = 3;
        price = 1;
        classId = 3;
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
    double price;
};

double Circle::getCircumference() const{
    return radius * radius * 3.1415 * price;
}

double Rectangle::getCircumference() const{
    return (length + width) * 2 * price;
}

double RightTriangle::getCircumference() const{
    return (side1 + side2 + sqrt(side1 * side1 + side2 * side2)) * price;
}

double Square::getCircumference() const{
    return side * 4 * price;
}

void Circle::getInfo() const{
    cout << "圆， 半径 " << radius << "，价格 " << this->getCircumference() << endl;
}

void Rectangle::getInfo() const{
    cout << "长方形， 长 " << length << "，宽 " << width << "，价格 " << getCircumference() << endl;
}

void RightTriangle::getInfo() const{
    cout << "三角形， 直角边 " << side1 << " 直角边 " << side2 << "，价格 " << this->getCircumference() << endl;
}

void Square::getInfo() const{
    cout << "正方形， 边长 " << side << "，价格 " << this->getCircumference() << endl;
}

int main() {
    Array <Shape *> shapes(100);
    int pos = 0, sz;
    string line;
    ofstream osCircle("Circle.dat", ios_base::out|ios_base::binary), osRectangle("Rectangle.dat", ios_base::out|ios_base::binary),
                osRightTriangle("RightTriangle.dat", ios_base::out|ios_base::binary), osSquare("Square.dat", ios_base::out|ios_base::binary);
    ifstream is;
    ifstream isCircle("Circle.dat", ios_base::in|ios_base::binary), isRectangle("Rectangle.dat", ios_base::in|ios_base::binary),
                isRightTriangle("RightTriangle.dat", ios_base::in|ios_base::binary), isSquare("Square.dat", ios_base::in|ios_base::binary);
    FileNotFoundException except;
    string err = "文件没有找到。";
    is.open("Sha1pes.txt", ios_base::in);
    if(!is.is_open()) {
        except.ErrorOpening(err);
        return 0;
    }
    else {
            getline(is, line);
            cout << "成功打开文件。";
    }
    int price[4];
    for(int i = 0; i < 4; i++) {
        price[i] = line[i] - '0';
    }
    while(is) {
        string line;
        int choice = 0;
        if (pos == shapes.getSize()) shapes.resize(pos * 2);
        getline(is, line);
        choice = line[0] - '0';
        if(choice == -1)  break;
        else {
                /*Circle cir;
                Rectangle rec;
                RightTriangle rtri;*/
                if(choice == 1){
                    double radius = line[1] - '0';
                    shapes[pos] = new Circle(radius, price[0]);
                    pos++;
                }
                else if(choice == 2){
                    double length = line[1] - '0', width = line[2] - '0';
                    shapes[pos] = new Rectangle(length, width, price[1]);
                    pos++;
                }
                else if(choice == 3){
                    double side1 = line[1] - '0', side2 = line[2] - '0';
                    shapes[pos] = new RightTriangle(side1, side2, price[2]);
                    pos++;
                }
                else if(choice == 4) {
                    double side = line[1] - '0';
                    shapes[pos] = new Square(side, price[3]);
                    pos++;
                }
                else {
                    cout << "请输入正确的数字" << endl;
                }
            }
        }
    is.close();
    sz = shapes.getSize() - 1;
    for(int i = 1; i < 7; i++) {
        Shape *temp = shapes[i];
        int posi = i;
        while(posi > 0 && *shapes[posi - 1] > *temp) {
            shapes[posi] = shapes[posi - 1];
            posi--;
        }
        shapes[posi] = temp;

    }
    int realpos;
    cout << "排序完成" << endl;
    cout << "存储信息" << endl;
    for(int i = 0; i < pos; i++, realpos++) {
        if(shapes[i] != NULL) {
            shapes[i] -> getInfo();
            int classId = shapes[i] -> classId;
            if(classId == 1) {
                osCircle.write(reinterpret_cast<char*>(&shapes[i]), sizeof(shapes[i]));
            }
            else if(classId == 2) {
                osRectangle.write(reinterpret_cast<char*>(&shapes[i]), sizeof(shapes[i]));
            }
            else if(classId == 4) {
                osSquare.write(reinterpret_cast<char*>(&shapes[i]), sizeof(shapes[i]));
            }
            else if(classId == 3) {
                osRightTriangle.write(reinterpret_cast<char*>(&shapes[i]), sizeof(shapes[i]));
            }
        }
    }
    osCircle.close();
    osRectangle.close();
    osSquare.close();
    osRightTriangle.close();
    cout << "读取信息" << endl;
    Array <Shape *> newShapes(100);
    pos = shapes.getSize() - 1;
    for(int i = 0; i < 7; i++)
        if(shapes[i] != NULL){
        int classId = shapes[i] -> classId;
        if(classId == 1) {
            isCircle.read(reinterpret_cast<char*>(&newShapes[i]), sizeof(shapes[i]));
            newShapes[i] -> getInfo();
        }
        else if(classId == 2) {
            isRectangle.read(reinterpret_cast<char*>(&newShapes[i]), sizeof(shapes[i]));
            newShapes[i] -> getInfo();

        }
        else if(classId == 4) {
            isSquare.read(reinterpret_cast<char*>(&newShapes[i]), sizeof(shapes[i]));
            newShapes[i] -> getInfo();

        }
        else if(classId == 3) {
            isRightTriangle.read(reinterpret_cast<char*>(&newShapes[i]), sizeof(shapes[i]));
            newShapes[i] -> getInfo();

        }
    }
    isCircle.close();
    isRectangle.close();
    isSquare.close();
    isRectangle.close();
    delete *shapes;
    delete *newShapes;
    return 0;
}



