#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int ID;
    string title;
    string author;
    bool available;  

    Book(int id, string t, string a, bool avail = true) {
        ID = id;
        title = t;
        author = a;
        available = avail;
    }

    void displayBook() {
        cout << "ID: " << ID << ", Title: " << title << ", Author: " << author;
        if (available)
            cout << ", Status: Available" << endl;
        else
            cout << ", Status: Borrowed" << endl;
    }
};

class Library {
private:
    Book** books;
    int bookCount;
    int capacity;

public:
    Library(int cap) {
        capacity = cap;
        bookCount = 0;
        books = new Book*[capacity];
    }

    void addBook(int id, string title, string author, bool availability = true) {
        if (bookCount < capacity) {
            books[bookCount] = new Book(id, title, author, availability);
            bookCount++;
            cout << "Book added: " << title << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    void borrowBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->ID == id) {
                if (books[i]->available) {
                    books[i]->available = false;
                    cout << "You borrowed: " << books[i]->title << endl;
                    return;
                } else {
                    cout << "Sorry, the book '" << books[i]->title << "' is already borrowed." << endl;
                    return;
                }
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->ID == id) {
                if (!books[i]->available) {
                    books[i]->available = true;
                    cout << "You returned: " << books[i]->title << endl;
                    return;
                } else {
                    cout << "The book '" << books[i]->title << "' is already available." << endl;
                    return;
                }
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayAvailableBooks() {
        cout << "Available Books:" << endl;
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->available) {
                books[i]->displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No available books." << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
        delete[] books;
    }
};

int main() {
    Library library(5);

    library.addBook(101, "Bastard of Istanbul", "ELIF SHAFAQ");
    library.addBook(102, "Verity", "Colleen Hoover", false);
    library.addBook(103, "Where the Lemon Trees Grow", "Syria");

    library.displayAvailableBooks();

    library.borrowBook(101);
    library.borrowBook(102);

    library.displayAvailableBooks();

    library.returnBook(101);

    library.displayAvailableBooks();

    return 0;
}
