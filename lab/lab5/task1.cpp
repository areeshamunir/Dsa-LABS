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
    int capacity;
    int count;

public:
    // Constructor
    myStack(int size) {
        capacity = size;
        count = 0;
        arr = new T[capacity];
    }

    // Push: Add element
    void push(T value) override {
        if (isFull()) {
            cout << "Stack is Full!" << endl;
        }
        else {
            arr[count] = value;
            count++;
            cout << "Element pushed successfully." << endl;
        }
    }

    // Pop: Remove top element
    T pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }

        count--;
        return arr[count];
    }

    // Top: Return top element
    T top() const override {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }

        return arr[count - 1];
    }

    // Check empty
    bool isEmpty() const override {
        return count == 0;
    }

    // Check full
    bool isFull() const override {
        return count == capacity;
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
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Display" << endl;
        cout << "0. Exit" << endl;
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
                cout << "Popped element: " << s.pop() << endl;
            else
                cout << "Stack is Empty!" << endl;
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top element: " << s.top() << endl;
            else
                cout << "Stack is Empty!" << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
            break;

        case 6:
            s.display();
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}