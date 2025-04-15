#ifndef Book_h
#define Book_h

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;

public:
    Book(std::string t, std::string a, std::string i);

    std::string gettitle() const;
    std::string getauthor() const;
    std::string getISBN() const;
};

#endif
