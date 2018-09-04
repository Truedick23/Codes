#include<iostream>
using namespace std;

class Automobile;

class Park {
public:
    Park(int );
    Park(){};
    void showInfo();
    int getNumberOfPlaces();
    void leaveCar();
    void enterCar();
    void incomeIncrease(int );
    ~Park() {delete[] spaces;}
    int getNumber();
    Automobile **spaces;
private:
    int totalNumber;
    int income;
    int numberOfCars;
};

class Automobile {
public:
    Automobile(){};
    void enter(Park *park);
    void leave(Park *park);
    string *getLicenseLocation() {
        return &license;
    }
    string getLicense();
    ~Automobile(){};
private:
    string license;
    int place;
protected:
    virtual void pay(Park *) = 0;
};

class Truck : public Automobile {
public:
    Truck(string, double );
    double getWeight();
    ~Truck(){};
private:
    double weight;
protected:
    void pay(Park *park){
       cout << getLicense() << " is currently left the park, paid 3 yuan. " << endl;
        park -> incomeIncrease(3);
    }
};

class Car : public Automobile {
public:
    Car(string, string );
    string getBrand();
    ~Car(){};
private:
    string brand;
protected:
    void pay(Park* park) {
       cout << getLicense() << " is currently left the park, paid 1 yuan. " << endl;
        park -> incomeIncrease(1);
    };
};

class Bus : public Automobile {
public:
    Bus(string, int );
    int getNumber();
    ~Bus(){};
private:
    int number;
protected:
    void pay(Park* park) {
       cout << getLicense() << " is currently left the park, paid 2 yuan. " << endl;
        park -> incomeIncrease(2);
    };
};

Truck::Truck(string license, double weight) {
    *(this -> getLicenseLocation()) = license;
    this -> weight = weight;
}

Bus::Bus(string license, int number) {
    *(this -> getLicenseLocation()) = license;
    this -> number = number;
}

Car::Car(string license, string brand) {
    *(this -> getLicenseLocation()) = license;
    this -> brand = brand;
}

Park::Park(int N) {
    totalNumber = N;
    spaces = new Automobile*[N];
    income = 0;
    numberOfCars = 0;
}

string Automobile::getLicense() {
    return license;
}

void Automobile::enter(Park *park) {
    if(park -> getNumber() == park -> getNumberOfPlaces()) {
        cout << "Unable to allocate space for " << license << endl;
        return;
    }
    park -> spaces[park -> getNumber()] = this;
    place = park -> getNumber();
    cout << license << " is currently in the park, allocating space" << endl;
    park -> enterCar();
}

void Automobile::leave(Park *park) {
    (park -> spaces)[place] = NULL;
    park -> leaveCar();
    pay(park);
}

int Park::getNumber() {
    return numberOfCars;
}

double Truck::getWeight() {
    return weight;
}

string Car::getBrand() {
    return brand;
}

int Bus::getNumber() {
    return number;
}

void Park::showInfo() {
    cout << "Currently " << numberOfCars << " cars in the park: ";
    for(int i = 0; i < totalNumber; i++)
        if((spaces + i) != NULL)
           cout << (*spaces + i) -> getLicense() << ", ";
    cout << endl << "Total income: " << income << " yuan. " << endl;
}

int Park::getNumberOfPlaces() {
    return totalNumber;
}

void Park::enterCar() {
    numberOfCars++;
}

void Park::leaveCar() {
    numberOfCars--;
}

void Park::incomeIncrease(int fee) {
    income += fee;
}

int main() {
    int N;
    cout << "Please input the number of parking spaces: ";
    cin >> N;
    Park *park = new Park(N);

    Car car1("続B-12345","安杵A6");
    car1.enter(park);

    Truck truck("続B-23456", 15);
    truck.enter(park);

    car1.leave(park);

    Bus bus("続B-34567", 50);
    bus.enter(park);

    park -> showInfo();

    Car car2("続B-45678","右瀧320");
    car2.enter(park);

    bus.leave(park);
    truck.leave(park);

    park -> showInfo();
    delete park;
}
