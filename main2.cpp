
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Product {
private:
    string name;
    double revenue;
    int day, month, year;

public:
    Product() {
        name = "";
        revenue = 0;
        day = month = year = 0;
    }

    Product(string n, double r, int d, int m, int y) {
        name = n;
        revenue = r;
        day = d;
        month = m;
        year = y;
    }

    string getName() {
        return name;
    }

    double getRevenue(int d, int m, int y) {
        if (day == d && month == m && year == y)
            return revenue;
        return 0;
    }

    virtual void displayInfo() {
        cout << name << ": " << revenue << endl;
    }

    virtual ~Product() = default;
};

class Drinks : public Product {
public:
    Drinks(string n, double r, int d, int m, int y)
        : Product(n, r, d, m, y) {}
};

class Foods : public Product {
public:
    Foods(string n, double r, int d, int m, int y)
        : Product(n, r, d, m, y) {}
};

double calculateRevenue(Product* products[], int size,
                        int d, int m, int y) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += products[i]->getRevenue(d, m, y);
    }

    return total;
}

int main() {
    Drinks coffee("Coffee", 1500000, 16, 10, 2026);
    Drinks tea("Tea", 800000, 16, 10, 2026);
    Drinks smoothies("Smoothies", 1200000, 16, 10, 2026);
    Drinks juices("Juices", 600000, 15, 10, 2026);

    Foods cake("Cake", 900000, 16, 10, 2026);
    Foods breads("Breads", 500000, 16, 10, 2026);

    Product* drinks[] = {
        &coffee, &tea, &smoothies, &juices
    };

    Product* foods[] = {
        &cake, &breads
    };

    int d, m, y;

    cout << "Enter date (dd mm yyyy): ";
    cin >> d >> m >> y;

    cout << fixed << setprecision(0);

    cout << "\nRevenue on "
         << setfill('0') << setw(2) << d << "/"
         << setw(2) << m << "/"
         << y << setfill(' ') << endl;

    cout << "Drinks: "
         << calculateRevenue(drinks, 4, d, m, y)
         << " VND" << endl;

    cout << "Foods: "
         << calculateRevenue(foods, 2, d, m, y)
         << " VND" << endl;

    return 0;
}
