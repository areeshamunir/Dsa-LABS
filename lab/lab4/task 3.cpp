#include <iostream>
using namespace std;

template <class T>
class List {
protected:
    T* arr;
    int maxSize, currentSize;

public:
    List(int m = 10, int c = 0) {
        maxSize = m;
        currentSize = c;
        arr = new T[maxSize];
    }

    List(const List<T>& x) {
        maxSize = x.maxSize;
        currentSize = x.currentSize;
        arr = new T[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = x.arr[i];
    }

    virtual void addElementAtFirstIndex(T) = 0;
    virtual void addElementAtLastIndex(T) = 0;
    virtual T removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    void display() {
        for (int i = 0; i < currentSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    virtual ~List() {
        delete[] arr;
    }
};

template <class T>
class MyList : public List<T> {
public:
    using List<T>::List;

    MyList(const MyList<T>& x) : List<T>(x) {}

    bool empty() {
        return this->currentSize == 0;
    }

    bool full() {
        return this->currentSize == this->maxSize;
    }

    int size() {
        return this->currentSize;
    }

    void addElementAtFirstIndex(T x) override {
        if (full()) return;

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = x;
        this->currentSize++;
    }

    void addElementAtLastIndex(T x) override {
        if (full()) return;

        this->arr[this->currentSize++] = x;
    }

    T removeElementFromEnd() override {
        if (empty()) return T();

        return this->arr[--this->currentSize];
    }

    void removeElementFromStart() override {
        if (empty()) return;

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool insertAt(int index, T value) {
        if (full() || index < 0 || index > size())
            return false;

        for (int i = size(); i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    T last() {
        if (empty()) return T();

        return this->arr[this->currentSize - 1];
    }

    bool search(T value) {
        for (int i = 0; i < size(); i++)
            if (this->arr[i] == value)
                return true;

        return false;
    }
};

int main() {
    MyList<int> l(5);
    int choice, value, index;

    do {
        cout << "\n1. Add at Start\n2. Add at End\n";
        cout << "3. Remove from Start\n4. Remove from End\n";
        cout << "5. Empty?\n6. Full?\n7. Size\n";
        cout << "8. Insert at Index\n9. Last Element\n";
        cout << "10. Search\n11. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            l.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            l.addElementAtLastIndex(value);
            break;

        case 3:
            l.removeElementFromStart();
            cout << "First element removed.\n";
            break;

        case 4:
            if (!l.empty())
                cout << "Removed: " << l.removeElementFromEnd() << endl;
            else
                cout << "List is empty.\n";
            break;

        case 5:
            cout << (l.empty() ? "List is empty\n" : "List is not empty\n");
            break;

        case 6:
            cout << (l.full() ? "List is full\n" : "List is not full\n");
            break;

        case 7:
            cout << "Size: " << l.size() << endl;
            break;

        case 8:
            cout << "Enter index and value: ";
            cin >> index >> value;
            cout << (l.insertAt(index, value) ?
                "Inserted successfully\n" : "Insertion failed\n");
            break;

        case 9:
            if (!l.empty())
                cout << "Last element: " << l.last() << endl;
            else
                cout << "List is empty.\n";
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (l.search(value) ? "Found\n" : "Not found\n");
            break;

        case 11:
            l.display();
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
    