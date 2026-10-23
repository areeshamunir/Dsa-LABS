#include <iostream>
#include <string>
using namespace std;

// Stack for storing text history
class HistoryStack {
private:
    string* arr;
    int capacity;
    int count;

public:
    HistoryStack(int size = 1000) {
        capacity = size;
        count = 0;
        arr = new string[capacity];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool push(string value) {
        if (isFull()) {
            cout << "History stack is full!" << endl;
            return false;
        }

        arr[count] = value;
        count++;
        return true;
    }

    string pop() {
        if (isEmpty())
            return "";

        count--;
        return arr[count];
    }

    // Clear history when a new edit is made
    void clear() {
        count = 0;
    }

    ~HistoryStack() {
        delete[] arr;
    }
};

int main() {
    string text = "";
    char ch;
    int choice;

    HistoryStack undoStack;
    HistoryStack redoStack;

    do {
        cout << "\n===== TEXT EDITOR =====" << endl;
        cout << "Current Text: " << text << endl;

        cout << "\n1. Type a character" << endl;
        cout << "2. Delete last character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display text" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character to type: ";
            cin >> ch;

            if (undoStack.push(text)) {
                redoStack.clear();
                text += ch;
                cout << "Character added." << endl;
            }
            break;

        case 2:
            if (text.empty()) {
                cout << "Text is already empty!" << endl;
            }
            else {
                if (undoStack.push(text)) {
                    redoStack.clear();
                    text.pop_back();
                    cout << "Last character deleted." << endl;
                }
            }
            break;

        case 3:
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo!" << endl;
            }
            else if (redoStack.push(text)) {
                text = undoStack.pop();
                cout << "Undo successful." << endl;
            }
            break;

        case 4:
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo!" << endl;
            }
            else if (undoStack.push(text)) {
                text = redoStack.pop();
                cout << "Redo successful." << endl;
            }
            break;

        case 5:
            cout << "Current Text: " << text << endl;
            break;

        case 6:
            cout << "Text editor closed." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}