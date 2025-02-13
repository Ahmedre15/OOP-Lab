#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string author;
    string publisher;

public:
  
    Book(string bookName, string ISBN, string author, string publisher) {
        this->bookName = bookName;
        this->ISBN = ISBN;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() { return this->bookName; }
    string getISBN() { return this->ISBN; }
    string getAuthor() { return this->author; }
    string getPublisher() { return this->publisher; }

    string getBookInfo() {
        return "Book Name: " + this->bookName + "\nISBN: " + this->ISBN + 
               "\nAuthor: " + this->author + "\nPublisher: " + this->publisher + "\n";
    }
};

int main() {
 
    Book books[5] = {
        Book("Dastaan-e-Mujahid", "9789693506611", "Naseem Hijazi", "Ilm-o-Irfan Publishers"),
        Book("Peer-e-Kamil", "9789690020943", "Umera Ahmed", "Ferozsons Publishers"),
        Book("Umrao Jaan Ada", "9789693511225", "Mirza Hadi Ruswa", "Lahore Academy"),
        Book("Zavia", "9789693511485", "Ashfaq Ahmed", "Sang-e-Meel Publications"),
        Book("Raja Gidh", "9789693500519", "Bano Qudsia", "Sang-e-Meel Publications")
    };

    for (int i = 0; i < 5; i++) {
        cout << "Book " << (i + 1) << " Information:\n";
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}
