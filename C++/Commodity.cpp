#include<iostream>
#include<iomanip>
using namespace std;

class Commodity {
public:
    Commodity(string ,double ,double );
    Commodity(const Commodity&);
    Commodity(){};
    void printInfo();
    double getPrice();
    double getNumber();
    string getName();
    ~Commodity(){};
private:
    string name;
    double price;
    double num;
};

class Cart {
public:
    Cart(Commodity item[20], int );
    Cart(const Cart&);
    void addItem(Commodity );
    void checkout();
    void printInvoice();
    ~Cart(){};
private:
    Commodity item[20];
    int kinds = 0;
};

Commodity::Commodity(string Name, double Price, double Number) {
    name = Name;
    price = Price;
    num = Number;
}

Commodity::Commodity(const Commodity &item) {
    name = item.name;
    price = item.price;
    num = item.num;
}

void Commodity::printInfo() {
    cout << "Name: " << name << endl
    << "Price: " << setprecision(2) << price << endl
    << "Number: " << setprecision(2) << num;
}

double Commodity::getPrice() {
    return price;
}

double Commodity::getNumber() {
    return num;
}

string Commodity::getName() {
    return name;
}

Cart::Cart(Commodity Item[20], int Kinds) {
    for(int i = 0; i < 20; i++) {
            item[i] = item[i];
    }
    kinds = Kinds;
}

Cart::Cart(const Cart& cart) {
    for(int i = 0; i < 20; i++) {
        item[i] = cart.item[i];
    }
    kinds = cart.kinds;
}

void Cart::addItem(Commodity newCommodity) {
    item[kinds++] = newCommodity;
}

void Cart::checkout() {
    double total = 0;
    for(int i = 0; i < kinds; i++) {
        total += item[i].getPrice()*item[i].getNumber();
    }
    cout << "You should pay " << total << " yuan in total." << endl;
}

void Cart::printInvoice() {
    cout << endl << "Commodities in your cart: " << endl;
    for(int i = 0; i < kinds; i++) {
       cout << "  #" << (i + 1) << endl << "Name: " << item[i].getName() << endl;
       cout << "Price: " << item[i].getPrice() << endl;
       cout << "Number: " << item[i].getNumber() << endl << endl;
    }
}


int main() {
    Commodity tShirt("Tshirt", 79, 2);
    Commodity suit("suit", 1099, 1);
    Commodity hat("hat", 129, 3);
    Commodity tv("tv set", 4899, 1);
    Commodity ac("air condition", 5280, 1);
    Commodity *emptyCommodity = NULL;

    Cart myCart(emptyCommodity, 0);
    myCart.addItem(tShirt);
    myCart.addItem(suit);
    myCart.addItem(hat);
    myCart.addItem(tv);
    myCart.addItem(ac);

    myCart.checkout();
    myCart.printInvoice();
    return 0;
}
