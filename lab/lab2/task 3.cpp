#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// ABSTRACT BASE CLASS
// =====================================================

class LibraryItem {
public:
    // Pure virtual functions
    virtual void display() = 0;
    virtual string getName() = 0;

    // Virtual destructor
    virtual ~LibraryItem() {}
};


// =====================================================
// BOOK CLASS
// =====================================================

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    // Constructor
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    // Implement pure virtual function
    void display() override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    // Return title
    string getName() override {
        return title;
    }

    // Getter for pages
    int getPages() {
        return pages;
    }

    // Getter for title
    string getTitle() {
        return title;
    }
};


// =====================================================
// NEWSPAPER CLASS
// =====================================================

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    // Constructor
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    // Implement pure virtual function
    void display() override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    // Return newspaper name
    string getName() override {
        return name;
    }

    // Getter for edition
    string getEdition() {
        return edition;
    }

    // Getter for newspaper name
    string getNewspaperName() {
        return name;
    }
};


// =====================================================
// TEMPLATE LINEAR SEARCH
// =====================================================

template <class T>
T* linearSearch(vector<T>& items, string key) {

    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == key) {
            return &items[i];
        }
    }

    return nullptr;
}


// =====================================================
// TEMPLATE BINARY SEARCH
// =====================================================

template <class T>
T* binarySearch(vector<T>& items, string key) {

    int low = 0;
    int high = items.size() - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (items[mid].getName() == key) {
            return &items[mid];
        }
        else if (items[mid].getName() < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return nullptr;
}


// =====================================================
// LIBRARY CLASS
// =====================================================

class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:

    // Add book
    void addBook(Book book) {
        books.push_back(book);
    }

    // Add newspaper
    void addNewspaper(Newspaper newspaper) {
        newspapers.push_back(newspaper);
    }


    // Display complete collection
    void displayCollection() {

        cout << "\n--- BOOKS ---\n";

        for (int i = 0; i < books.size(); i++) {
            books[i].display();
            cout << endl;
        }

        cout << "--- NEWSPAPERS ---\n";

        for (int i = 0; i < newspapers.size(); i++) {
            newspapers[i].display();
            cout << endl;
        }
    }


    // Sort books by pages
    void sortBooksByPages() {

        sort(books.begin(), books.end(),
            [](Book& a, Book& b) {
                return a.getPages() < b.getPages();
            });
    }


    // Sort newspapers by edition
    void sortNewspapersByEdition() {

        sort(newspapers.begin(), newspapers.end(),
            [](Newspaper& a, Newspaper& b) {
                return a.getEdition() < b.getEdition();
            });
    }


    // Search book by title
    Book* searchBookByTitle(string title) {

        // Linear search
        for (int i = 0; i < books.size(); i++) {

            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }

        return nullptr;
    }


    // Search newspaper by name
    Newspaper* searchNewspaperByName(string name) {

        // Linear search
        for (int i = 0; i < newspapers.size(); i++) {

            if (newspapers[i].getNewspaperName() == name) {
                return &newspapers[i];
            }
        }

        return nullptr;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

int main() {

    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1(
        "Washington Post",
        "2024-10-13",
        "Morning Edition"
    );

    Newspaper newspaper2(
        "The Times",
        "2024-10-12",
        "Weekend Edition"
    );


    // Create library object
    Library library;


    // Add books and newspapers
    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);


    // Display before sorting
    cout << "Before Sorting:\n";
    library.displayCollection();


    // Sort
    library.sortBooksByPages();
    library.sortNewspapersByEdition();


    // Display after sorting
    cout << "\nAfter Sorting:\n";
    library.displayCollection();


    // Search for book
    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {

        cout << "\nFound Book:\n";
        foundBook->display();

    }
    else {

        cout << "\nBook not found.\n";
    }


    // Search for newspaper
    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper) {

        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();

    }
    else {

        cout << "\nNewspaper not found.\n";
    }


    return 0;
}