#include <iostream>
using namespace std;

// Abstract class
class Employee {
public:
    // Pure virtual function
    virtual double calculateSalary() = 0;
};

// Full-Time Employee
class FullTimeEmployee : public Employee {
private:
    double fixedSalary;

public:
    // Constructor
    FullTimeEmployee(double salary) {
        fixedSalary = salary;
    }

    // Implement calculateSalary()
    double calculateSalary() override {
        return fixedSalary;
    }
};

// Part-Time Employee
class PartTimeEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    // Constructor
    PartTimeEmployee(double hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    // Implement calculateSalary()
    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }
};

int main() {
    // Create a full-time employee
    FullTimeEmployee fullTime(50000);

    // Create a part-time employee
    PartTimeEmployee partTime(80, 500);

    // Display salaries
    cout << "Full-Time Employee Salary = "
        << fullTime.calculateSalary() << endl;

    cout << "Part-Time Employee Salary = "
        << partTime.calculateSalary() << endl;

    return 0;
}