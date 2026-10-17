#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    virtual void display() = 0;
};

class Book : public Item {
public:
    string title, author;
    int pages;

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() override {
        cout << title << " " << author << " "
            << pages << " pages\n";
    }
};

class Newspaper : public Item {
public:
    string name, date, edition;

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    void display() override {
        cout << name << " " << date << " "
            << edition << endl;
    }
};

class Library {
public:
    vector<Book> books;
    vector<Newspaper> papers;

    void addBook(Book b) {
        books.push_back(b);
    }

    void addNewspaper(Newspaper n) {
        papers.push_back(n);
    }

    void display() {
        for (auto b : books) b.display();
        for (auto n : papers) n.display();
    }

    void sortBooks() {
        for (int i = 0; i < books.size(); i++)
            for (int j = 0; j + 1 < books.size(); j++)
                if (books[j].pages > books[j + 1].pages)
                    swap(books[j], books[j + 1]);
    }

    void sortPapers() {
        for (int i = 0; i < papers.size(); i++)
            for (int j = 0; j + 1 < papers.size(); j++)
                if (papers[j].edition > papers[j + 1].edition)
                    swap(papers[j], papers[j + 1]);
    }
};

int main() {
    Library l;

    l.addBook(Book("Catcher in the Rye", "Salinger", 277));
    l.addBook(Book("To Kill a Mockingbird", "Harper Lee", 324));

    l.addNewspaper(Newspaper("Washington Post", "2024-10-13", "Morning Edition"));
    l.addNewspaper(Newspaper("The Times", "2024-10-12", "Weekend Edition"));

    cout << "Before Sorting:\n";
    l.display();

    l.sortBooks();
    l.sortPapers();

    cout << "\nAfter Sorting:\n";
    l.display();

    for (auto b : l.books)
        if (b.title == "Catcher in the Rye")
            b.display();

    for (auto n : l.papers)
        if (n.name == "The Times")
            n.display();

    return 0;
}