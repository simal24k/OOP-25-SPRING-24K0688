#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pd, string uid, string pub)
        : title(t), publicationDate(pd), uniqueID(uid), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
    virtual void checkOut() { cout << "Checking out: " << title << endl; }
    virtual void returnItem() { cout << "Returning: " << title << endl; }
    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pd, string uid, string pub, string a, string isbn, int nPages)
        : Media(t, pd, uid, pub), author(a), ISBN(isbn), numberOfPages(nPages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    double rating;
public:
    DVD(string t, string pd, string uid, string pub, string d, int dur, double r)
        : Media(t, pd, uid, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nRating: " << rating << "/5" << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pd, string uid, string pub, string art, string g, int nTracks)
        : Media(t, pd, uid, pub), artist(art), genre(g), numberOfTracks(nTracks) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nGenre: " << genre << "\nTracks: " << numberOfTracks << endl;
    }
};

int main() {
    Book b("C++ Primer", "2020", "B123", "Pearson", "Lippman", "1234567890", 800);
    DVD d("Inception", "2010", "D456", "Warner Bros", "Christopher Nolan", 148, 4.8);
    CD c("Thriller", "1982", "C789", "Epic Records", "Michael Jackson", "Pop", 9);

    cout << "\n--- Book Info ---\n";
    b.displayInfo();
    b.checkOut();
    b.returnItem();

    cout << "\n--- DVD Info ---\n";
    d.displayInfo();
    d.checkOut();
    d.returnItem();

    cout << "\n--- CD Info ---\n";
    c.displayInfo();
    c.checkOut();
    c.returnItem();
    
    return 0;
}
//selfnnote: same as Q4
