#include <iostream>
using namespace std;

class Book {
protected:
    string genre;
public:
    Book(string g) : genre(g) {}
    virtual void displayDetails() = 0;
};

class Novel : public Book {
private:
    string title, author;
public:
    Novel(string t, string a) : Book("Novel"), title(t), author(a) {}
    void displayDetails() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n";
    }
};

class Mystery : public Book {
private:
    string title, author;
public:
    Mystery(string t, string a) : Book("Mystery"), title(t), author(a) {}
    void displayDetails() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n";
    }
};

int main() {
    Novel n1("The Great Gatsby", "Scott Fitzgerald");
    Mystery m1("Sherlock Holmes", "Arthur Conan Doyle");
    
    n1.displayDetails();
    cout << "-------------------\n";
    m1.displayDetails();
    
    return 0;
}