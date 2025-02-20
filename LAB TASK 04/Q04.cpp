#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author, publisher;
    double price;
    int stock;

public:
    Book(string t, string a, string p, double pr, int s) 
        : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    void showDetails() {
        cout << "Title: " << title << "\nAuthor: " << author 
             << "\nPublisher: " << publisher << "\nPrice: $" << price 
             << "\nStock: " << stock << endl;
    }

    void purchase(int copies) {
        if (copies <= stock) {
            cout << "Total cost: $" << copies * price << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    const int SIZE = 3; 
    Book books[SIZE] = {
        {"C++ Primer", "Stanley", "Pearson", 45.5, 10},
        {"Java Basics", "John Doe", "McGraw", 50.0, 5},
        {"Python Guide", "Alice", "O'Reilly", 60.0, 8}
    };

    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter book author: ";
    getline(cin, searchAuthor);

    for (int i = 0; i < SIZE; i++) {
        if (books[i].isAvailable(searchTitle, searchAuthor)) {
            books[i].showDetails();
            int copies;
            cout << "Enter number of copies required: ";
            cin >> copies;
            books[i].purchase(copies);
            return 0;
        }
    }

    cout << "Book not available" << endl;
    return 0;
}
