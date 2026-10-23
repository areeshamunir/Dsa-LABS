#include <iostream>
using namespace std;

// 1. Abstract Class
template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractStack() {}
};

// 2. Child Class
template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int capacity;
    int count;
    int minCount;

public:
    // Constructor
    myStack(int size) {
        capacity = size;
        count = 0;
        minCount = 0;

        arr = new T[capacity];
        minArr = new T[capacity];
    }

    // Push element into stack
    void push(T value) override {
        if (isFull()) {
            cout << "Stack is Full!" << endl;
            return;
        }

        arr[count] = value;
        count++;

        // Maintain minimum stack
        if (minCount == 0 ||
            value <= minArr[minCount - 1]) {
            minArr[minCount] = value;
            minCount++;
        }

        cout << "Element pushed successfully." << endl;
    }

    // Pop top element
    T pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }

        T value = arr[count - 1];
        count--;

        // Remove from minimum stack if needed
        if (value == minArr[minCount - 1]) {
            minCount--;
        }

        return value;
    }

    // Return top element
    T top() const override {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }

        return arr[count - 1];
    }

    // Check if empty
    bool isEmpty() const override {
        return count == 0;
    }

    // Check if full
    bool isFull() const override {
        return count == capacity;
    }

    // Get minimum in O(1) time
    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }

        return minArr[minCount - 1];
    }

    // Display from top to bottom
    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << "Stack (Top to Bottom):" << endl;

        for (int i = count - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    // Destructor
    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }
};

// 3. Main Function
int main() {
    int size;

    cout << "Enter stack size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    myStack<int> s(size);

    int choice, value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Display stack elements" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            if (!s.isEmpty())
                cout << "Popped element: "
                << s.pop() << endl;
            else
                cout << "Stack is Empty!" << endl;
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top element: "
                << s.top() << endl;
            else
                cout << "Stack is Empty!" << endl;
            break;

        case 4:
            cout << (s.isEmpty()
                ? "Stack is Empty."
                : "Stack is not Empty.")
                << endl;
            break;

        case 5:
            cout << (s.isFull()
                ? "Stack is Full."
                : "Stack is not Full.")
                << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            if (!s.isEmpty())
                cout << "Minimum element: "
                << s.getMin() << endl;
            else
                cout << "Stack is Empty!" << endl;
            break;

        case 8:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}