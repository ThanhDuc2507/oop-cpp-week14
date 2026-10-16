
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;

public:
    Employee() {
        id = 0;
        name = "";
    }

    Employee(int id, string name) {
        this->id = id;
        this->name = name;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }

    virtual double calculateSalary(int month, int year) {
        return 0;
    }

    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 0;
        year = 0;
    }

    HourlyEmployee(int id, string name, double hours,
                   double salaryPerHour, int month, int year)
        : Employee(id, name) {
        this->hours = hours;
        this->salaryPerHour = salaryPerHour;
        this->month = month;
        this->year = year;
    }

    double getHours() {
        return hours;
    }

    void setHours(double hours) {
        this->hours = hours;
    }

    double getSalaryPerHour() {
        return salaryPerHour;
    }

    void setSalaryPerHour(double salaryPerHour) {
        this->salaryPerHour = salaryPerHour;
    }

    int getMonth() {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) override {
        if (this->month == month && this->year == year)
            return hours * salaryPerHour;

        return 0;
    }

    void display() override {
        Employee::display();
        cout << "Type: Hourly Employee" << endl;
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: "
             << calculateSalary(month, year) << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0;
        month = 0;
        year = 0;
    }

    MonthlyEmployee(int id, string name, double monthlySalary,
                    int month, int year)
        : Employee(id, name) {
        this->monthlySalary = monthlySalary;
        this->month = month;
        this->year = year;
    }

    double getMonthlySalary() {
        return monthlySalary;
    }

    void setMonthlySalary(double monthlySalary) {
        this->monthlySalary = monthlySalary;
    }

    int getMonth() {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) override {
        if (this->month == month && this->year == year)
            return monthlySalary;

        return 0;
    }

    void display() override {
        Employee::display();
        cout << "Type: Monthly Employee" << endl;
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: "
             << calculateSalary(month, year) << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month;
    int year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0;
        month = 0;
        year = 0;
    }

    DailyEmployee(int id, string name, int numberOfDays,
                  double salaryPerDay, int month, int year)
        : Employee(id, name) {
        this->numberOfDays = numberOfDays;
        this->salaryPerDay = salaryPerDay;
        this->month = month;
        this->year = year;
    }

    int getNumberOfDays() {
        return numberOfDays;
    }

    void setNumberOfDays(int numberOfDays) {
        this->numberOfDays = numberOfDays;
    }

    double getSalaryPerDay() {
        return salaryPerDay;
    }

    void setSalaryPerDay(double salaryPerDay) {
        this->salaryPerDay = salaryPerDay;
    }

    int getMonth() {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) override {
        if (this->month == month && this->year == year)
            return numberOfDays * salaryPerDay;

        return 0;
    }

    void display() override {
        Employee::display();
        cout << "Type: Daily Employee" << endl;
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: "
             << calculateSalary(month, year) << endl;
    }
};

int main() {
    HourlyEmployee e1(1, "An", 100, 50000, 10, 2026);
    MonthlyEmployee e2(2, "Binh", 12000000, 10, 2026);
    DailyEmployee e3(3, "Cuong", 22, 300000, 10, 2026);

    cout << "===== HOURLY EMPLOYEE =====" << endl;
    e1.display();

    cout << "\n===== MONTHLY EMPLOYEE =====" << endl;
    e2.display();

    cout << "\n===== DAILY EMPLOYEE =====" << endl;
    e3.display();

    int month = 10;
    int year = 2026;

    cout << "\n===== SALARY REPORT =====" << endl;
    cout << "Hourly employee salary: "
         << e1.calculateSalary(month, year) << endl;
    cout << "Monthly employee salary: "
         << e2.calculateSalary(month, year) << endl;
    cout << "Daily employee salary: "
         << e3.calculateSalary(month, year) << endl;

    return 0;
}
