#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string cars[8];
    int count;

public:
    myCarStack() {
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == 8;
    }

    int totalCars() const {
        return count;
    }

    bool searchCar(string carNo) const {
        for (int i = 0; i < count; i++) {
            if (cars[i] == carNo)
                return true;
        }
        return false;
    }

    void parkCar(string carNo) {
        if (isFull()) {
            cout << "Parking lot is full!" << endl;
            return;
        }

        if (searchCar(carNo)) {
            cout << "This car is already parked!" << endl;
            return;
        }

        cars[count] = carNo;
        count++;
        cout << "Car parked successfully." << endl;
    }

    void removeCar(string carNo) {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return;
        }

        // Temporary stack to hold cars
        string temp[8];
        int tempCount = 0;

        // Move cars until the required car is on top
        while (count > 0 && cars[count - 1] != carNo) {
            temp[tempCount] = cars[count - 1];
            tempCount++;
            count--;
        }

        if (count == 0) {
            // Restore all cars if car was not found
            while (tempCount > 0) {
                cars[count] = temp[tempCount - 1];
                count++;
                tempCount--;
            }

            cout << "Car not found!" << endl;
            return;
        }

        // Remove the required car
        cout << "Car removed: " << cars[count - 1] << endl;
        count--;

        // Put temporarily removed cars back
        while (tempCount > 0) {
            cars[count] = temp[tempCount - 1];
            count++;
            tempCount--;
        }
    }

    void displayCars() const {
        if (isEmpty()) {
            cout << "No cars parked." << endl;
            return;
        }

        cout << "\nCars currently parked (Top to Bottom):"
            << endl;

        for (int i = count - 1; i >= 0; i--) {
            cout << cars[i] << endl;
        }
    }
};

int main() {
    myCarStack parking;
    int choice;
    string carNo;

    do {
        cout << "\n===== PARKING LOT MENU =====" << endl;
        cout << "1. Park a new car" << endl;
        cout << "2. Remove a car" << endl;
        cout << "3. View parked cars" << endl;
        cout << "4. Total cars parked" << endl;
        cout << "5. Search for a car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> carNo;
            parking.parkCar(carNo);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNo;
            parking.removeCar(carNo);
            break;

        case 3:
            parking.displayCars();
            break;

        case 4:
            cout << "Total cars parked: "
                << parking.totalCars() << "/8" << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNo;

            if (parking.searchCar(carNo))
                cout << "Car is present in parking lot."
                << endl;
            else
                cout << "Car not found!" << endl;
            break;

        case 6:
            cout << "Parking system closed." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}