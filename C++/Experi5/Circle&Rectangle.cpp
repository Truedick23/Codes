#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

struct Point {
    int x;
    int y;
};

void displayMenu() {
    for(int i = 0; i < 30; i++)
        cout << '*';
    cout << endl;
    cout << "    1. Circle" << endl;
    cout << "    2. Rectangle" << endl;
    cout << "    0. Exit" << endl;
    for(int i = 0; i < 30; i++)
        cout << '*';
    cout << endl;
    cout << "Please select the shape: ";
    return;
}

void getTwoPoints(struct Point *startP, struct Point *endP) {
    cout << "Please input the coordinate (x, y) of the start point :";
    cin >> startP->x >> startP->y;
    cout << "Please input the coordinate (x, y) of the end point:";
    cin >> endP->x >> endP->y;
}

void printPoint(struct Point *point) {
    printf("(%d, %d)", point->x, point->y);
}

void drawCircle(struct Point *startP, struct Point *endP) {
    int radius;
    int marginX, marginY;
    marginX = startP -> x - endP -> x, marginY = startP -> y - endP -> y;
    Point center;
    center.x = (startP->x + endP->x) / 2;
    center.y = (startP->y + endP->y) / 2;
    if (marginX != marginY) cout << "Not a circle, select again" << endl;
    else {
        cout << "Draw a circle at center ";
        printPoint(&center);
        cout << " with radius " << abs(marginX / 2) << endl;
    }
    return;
}

void drawRectangle(struct Point *startP, struct Point *endP) {
    int width = endP->x - startP->x;
    int height = endP->y - startP->y;
    cout << "Draw a rectangle at topleft ";
    printPoint(startP);
    cout << ", whose width is " << width << " and height is " << height << endl;
}

int main() {
    int choice;
    struct Point startP, endP;
    while (choice) {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            getTwoPoints(&startP, &endP);
            drawCircle(&startP, &endP);
            break;
        case 2:
            getTwoPoints(&startP, &endP);
            drawRectangle(&startP, &endP);
            break;
        case 0:
            cout << "Good Bye!" << endl;
            break;
        default:
            cout << "Not supported! Please select again!" << endl;
            break;
        }
    }
}


