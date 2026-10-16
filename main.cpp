
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle {
private:
    string id;
    string brand;
    double pricePerDay;

public:
    Vehicle() {
        id = "";
        brand = "";
        pricePerDay = 0;
    }

    Vehicle(string id, string brand, double pricePerDay) {
        this->id = id;
        this->brand = brand;
        this->pricePerDay = pricePerDay;
    }

    string getId() {
        return id;
    }

    void setId(string id) {
        this->id = id;
    }

    string getBrand() {
        return brand;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    double getPricePerDay() {
        return pricePerDay;
    }

    void setPricePerDay(double pricePerDay) {
        this->pricePerDay = pricePerDay;
    }

    virtual void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Brand: " << brand << endl;
        cout << "Price per day: " << pricePerDay << endl;
    }

    virtual double calculateRentalFee(int days) {
        return days * pricePerDay;
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle() {
        seats = 0;
    }

    Car(string id, string brand, double pricePerDay, int seats)
        : Vehicle(id, brand, pricePerDay) {
        this->seats = seats;
    }

    int getSeats() {
        return seats;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    void displayInfo() override {
        cout << "Type: Car" << endl;
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = days * getPricePerDay();

        if (days >= 7) {
            fee *= 0.9;
        }

        return fee;
    }
};

class Motorbike : public Vehicle {
private:
    int engineCapacity;

public:
    Motorbike() : Vehicle() {
        engineCapacity = 0;
    }

    Motorbike(string id, string brand, double pricePerDay,
              int engineCapacity)
        : Vehicle(id, brand, pricePerDay) {
        this->engineCapacity = engineCapacity;
    }

    int getEngineCapacity() {
        return engineCapacity;
    }

    void setEngineCapacity(int engineCapacity) {
        this->engineCapacity = engineCapacity;
    }

    void displayInfo() override {
        cout << "Type: Motorbike" << endl;
        Vehicle::displayInfo();
        cout << "Engine capacity: " << engineCapacity << " cc" << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = days * getPricePerDay();

        if (days >= 5) {
            fee *= 0.95;
        }

        return fee;
    }
};

class Truck : public Vehicle {
private:
    double transportFee;
    double loadCapacity;

public:
    Truck() : Vehicle() {
        transportFee = 0;
        loadCapacity = 0;
    }

    Truck(string id, string brand, double pricePerDay,
          double transportFee, double loadCapacity)
        : Vehicle(id, brand, pricePerDay) {
        this->transportFee = transportFee;
        this->loadCapacity = loadCapacity;
    }

    double getTransportFee() {
        return transportFee;
    }

    void setTransportFee(double transportFee) {
        this->transportFee = transportFee;
    }

    double getLoadCapacity() {
        return loadCapacity;
    }

    void setLoadCapacity(double loadCapacity) {
        this->loadCapacity = loadCapacity;
    }

    void displayInfo() override {
        cout << "Type: Truck" << endl;
        Vehicle::displayInfo();
        cout << "Transport fee: " << transportFee << endl;
        cout << "Load capacity: " << loadCapacity << " tons" << endl;
    }

    double calculateRentalFee(int days) override {
        return days * getPricePerDay() + transportFee;
    }
};

int main() {
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("C01", "Toyota", 1000000, 7));
    vehicles.push_back(new Car("C02", "Honda", 800000, 5));
    vehicles.push_back(new Motorbike("M01", "Honda", 150000, 150));
    vehicles.push_back(new Motorbike("M02", "Yamaha", 120000, 125));
    vehicles.push_back(new Truck("T01", "Hyundai", 2000000, 500000, 5));
    vehicles.push_back(new Truck("T02", "Isuzu", 2500000, 700000, 10));

    int days;
    cout << "Enter rental days: ";
    cin >> days;

    if (days <= 0) {
        cout << "Rental days must be greater than 0." << endl;

        for (Vehicle* v : vehicles) {
            delete v;
        }

        return 0;
    }

    double totalRevenue = 0;
    double maxFee = -1;
    Vehicle* mostExpensive = nullptr;

    cout << fixed << setprecision(0);

    for (Vehicle* v : vehicles) {
        cout << "\n====================" << endl;
        v->displayInfo();

        double fee = v->calculateRentalFee(days);

        cout << "Rental days: " << days << endl;
        cout << "Rental fee: " << fee << " VND" << endl;

        totalRevenue += fee;

        if (fee > maxFee) {
            maxFee = fee;
            mostExpensive = v;
        }
    }

    cout << "\n====================" << endl;
    cout << "Total rental revenue: "
         << totalRevenue << " VND" << endl;

    cout << "\nVehicle with the highest rental fee:" << endl;

    if (mostExpensive != nullptr) {
        mostExpensive->displayInfo();
        cout << "Highest rental fee: "
             << maxFee << " VND" << endl;
    }

    for (Vehicle* v : vehicles) {
        delete v;
    }

    vehicles.clear();

    return 0;
}
