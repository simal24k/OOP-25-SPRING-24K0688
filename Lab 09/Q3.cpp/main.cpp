#include <iostream>
#include "Book.h"
#include <string>

int main() {
    Book book1("1984", "George Orwell", "9780451524935");

    std::cout << "Title : " << book1.gettitle() << std::endl;
    std::cout << "Author: " << book1.getauthor() << std::endl;
    std::cout << "ISBN  : " << book1.getISBN() << std::endl;

    return 0;
}
