#include <iostream>
using namespace std;

class Employee {
public:
    virtual void calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
public:
    int salary;

    void calculateSalary() {
        cout << "Full Time Salary: " << salary << endl;
    }
};

class PartTimeEmployee : public Employee {
public:
    int hours, rate;

    void calculateSalary() {
        cout << "Part Time Salary: " << hours * rate << endl;
    }
};

int main() {
    FullTimeEmployee f;
    f.salary = 50000;

    PartTimeEmployee p;
    p.hours = 20;
    p.rate = 500;

    f.calculateSalary();
    p.calculateSalary();

    return 0;
}