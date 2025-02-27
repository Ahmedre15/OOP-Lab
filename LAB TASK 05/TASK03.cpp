#include <iostream>
#include <string>

using namespace std;

class Book {
    string title;
    string isbn;
public:
    Book(string t, string i) : title(t), isbn(i) {
        cout << "New Book Added: " << title << " (ISBN: " << isbn << ")" << endl;
    }

    ~Book() {
        cout << "Removing Book: " << title << " (ISBN: " << isbn << ")" << endl;
    }

    string getISBN() { return isbn; }
    string getTitle() { return title; }
};

class Catalog {
    Book* storedBooks[100];
    string storedIsbns[100];
    int totalBooks;
public:
    Catalog() : totalBooks(0) {}

    void insertBook(Book* book) {
        storedBooks[totalBooks] = book;
        storedIsbns[totalBooks] = book->getISBN();
        totalBooks++;
    }

    void deleteBook(string isbn) {
        for (int i = 0; i < totalBooks; i++) {
            if (storedIsbns[i] == isbn) {
                for (int j = i; j < totalBooks - 1; j++) {
                    storedBooks[j] = storedBooks[j + 1];
                    storedIsbns[j] = storedIsbns[j + 1];
                }
                totalBooks--;
                return;
            }
        }
    }

    Book* searchByISBN(string isbn) {
        for (int i = 0; i < totalBooks; i++) {
            if (storedIsbns[i] == isbn) {
                return storedBooks[i];
            }
        }
        return nullptr;
    }
};

class Library {
    Catalog catalog;
    Book* bookCollection[100];
    int collectionSize;
public:
    Library() : collectionSize(0) {}

    void addNewBook(Book* book) {
        bookCollection[collectionSize] = book;
        catalog.insertBook(book);
        collectionSize++;
    }

    void removeBookByISBN(string isbn) {
        for (int i = 0; i < collectionSize; i++) {
            if (bookCollection[i]->getISBN() == isbn) {
                for (int j = i; j < collectionSize - 1; j++) {
                    bookCollection[j] = bookCollection[j + 1];
                }
                collectionSize--;
                break;
            }
        }
        catalog.deleteBook(isbn);
    }

    void findBookInCatalog(string isbn) {
        Book* book = catalog.searchByISBN(isbn);
        if (book)
            cout << " Book Available: " << book->getTitle() << endl;
        else
            cout << " No Record Found for ISBN: " << isbn << endl;
    }
};

int main() {
    Library myLibrary;

    Book book1("Mastering C++", "AB123");
    Book book2("Data Structures & Algorithms", "XY456");

    myLibrary.addNewBook(&book1);
    myLibrary.addNewBook(&book2);

    myLibrary.findBookInCatalog("AB123");
    myLibrary.findBookInCatalog("ZZ999");

    myLibrary.removeBookByISBN("AB123");
    myLibrary.findBookInCatalog("AB123");

    return 0;
}
