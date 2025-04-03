#include <iostream>
#include <cstring>
using namespace std;
class Media {
protected:
    char title[100], publisher[50];
    int uniqueID;
    char publicationDate[20];

public:
    Media(int id, const char* t, const char* pubDate, const char* pub) {
        uniqueID = id;
        strcpy(title, t);
        strcpy(publicationDate, pubDate);
        strcpy(publisher, pub);
    }

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nPublisher: " << publisher << "\nUnique ID: " << uniqueID << endl;
    }

    void checkOut() {
        cout << "Item with ID " << uniqueID << " checked out.\n";
    }

    void returnItem() {
        cout << "Item with ID " << uniqueID << " returned.\n";
    }

    // Function overloading for searching media by title or author
    virtual bool searchByTitle(const char* t) {
        return strcmp(title, t) == 0;
    }

    virtual bool searchByPublisher(const char* pub) {
        return strcmp(publisher, pub) == 0;
    }

    virtual bool searchByPublicationDate(const char* date) {
        return strcmp(publicationDate, date) == 0;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    char author[50], ISBN[20];
    int numberOfPages;

public:
    Book(int id, const char* t, const char* pubDate, const char* pub, const char* auth, const char* isbn, int pages)
        : Media(id, t, pubDate, pub) {
        strcpy(author, auth);
        strcpy(ISBN, isbn);
        numberOfPages = pages;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << numberOfPages << endl;
    }

    bool searchByAuthor(const char* auth) {
        return strcmp(author, auth) == 0;
    }
};

class DVD : public Media {
private:
    char director[50], rating[10];
    int duration; // in minutes

public:
    DVD(int id, const char* t, const char* pubDate, const char* pub, const char* dir, int dur, const char* rate)
        : Media(id, t, pubDate, pub) {
        strcpy(director, dir);
        duration = dur;
        strcpy(rating, rate);
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << endl;
    }

    bool searchByDirector(const char* dir) {
        return strcmp(director, dir) == 0;
    }
};

class CD : public Media {
private:
    char artist[50], genre[30];
    int numberOfTracks;

public:
    CD(int id, const char* t, const char* pubDate, const char* pub, const char* art, int tracks, const char* gen)
        : Media(id, t, pubDate, pub) {
        strcpy(artist, art);
        numberOfTracks = tracks;
        strcpy(genre, gen);
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }

    bool searchByArtist(const char* art) {
        return strcmp(artist, art) == 0;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(int id, const char* t, const char* pubDate, const char* pub, int issue)
        : Media(id, t, pubDate, pub) {
        issueNumber = issue;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }

    bool searchByIssueNumber(int issue) {
        return issueNumber == issue;
    }
};

int main() {
    Book b1(101, "C++ Programming", "2023-01-01", "Tech Press", "John Doe", "123", 350);
    DVD d1(102, "Interstellar", "2020-06-15", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD c1(103, "Abbey Road", "1969-09-26", "Apple Records", "The Beatles", 17, "Rock");
    Magazine m1(104, "National Geographic", "2023-03-01", "NatGeo", 325);

    cout << "\n[Book Information]\n";
    b1.displayInfo();
    cout << "\n[DVD Information]\n";
    d1.displayInfo();
    cout << "\n[CD Information]\n";
    c1.displayInfo();
    cout << "\n[Magazine Information]\n";
    m1.displayInfo();

    cout << "\nSearching for book by title 'C++ Programming':\n";
    if (b1.searchByTitle("C++ Programming")) {
        cout << "Book found!\n";
    } else {
        cout << "Book not found.\n";
    }

    cout << "\nSearching for DVD by director 'Christopher Nolan':\n";
    if (d1.searchByDirector("Christopher Nolan")) {
        cout << "DVD found!\n";
    } else {
        cout << "DVD not found.\n";
    }

    cout << "\nSearching for CD by artist 'The Beatles':\n";
    if (c1.searchByArtist("The Beatles")) {
        cout << "CD found!\n";
    } else {
        cout << "CD not found.\n";
    }

    cout << "\nSearching for Magazine by issue number 325:\n";
    if (m1.searchByIssueNumber(325)) {
        cout << "Magazine found!\n";
    } else {
        cout << "Magazine not found.\n";
    }
    return 0;
}
