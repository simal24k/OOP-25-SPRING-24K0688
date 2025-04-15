#include "Book.h"

Book::Book(std::string t, std::string a, std::string i) : title(t), author(a), ISBN(i) {}

std::string Book::gettitle() const {
    return title;
}

std::string Book::getauthor() const {
    return author;
}

std::string Book::getISBN() const {
    return ISBN;
}
