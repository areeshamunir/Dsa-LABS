#include <iostream>
using namespace std;

template <class Type>
class List {
protected:
    Type* arr;
    int maxSize, currentSize;

public:
    List(int m = 10, int c = 0) {
        maxSize = m;
        currentSize = c;
        arr = new Type[maxSize];
    }

    List(const List<Type>& obj) {
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;
        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = obj.arr[i];
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
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

template <class Type>
class ArrayList : public List<Type> {
public:
    using List<Type>::List;

    void addElementAtFirstIndex(Type x) override {
        if (this->currentSize == this->maxSize) return;

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = x;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type x) override {
        if (this->currentSize == this->maxSize) return;

        this->arr[this->currentSize++] = x;
    }

    Type removeElementFromEnd() override {
        if (this->currentSize == 0) return Type();

        return this->arr[--this->currentSize];
    }

    void removeElementFromStart() override {
        if (this->currentSize == 0) return;

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }
};

int main() {
    ArrayList<int> list(5);

    list.addElementAtLastIndex(10);
    list.addElementAtLastIndex(20);
    list.addElementAtFirstIndex(5);

    cout << "List: ";
    list.display();

    cout << "Removed: " << list.removeElementFromEnd() << endl;

    list.removeElementFromStart();

    cout << "Final list: ";
    list.display();

    ArrayList<int> copy(list);
    cout << "Copied list: ";
    copy.display();

    return 0;
}