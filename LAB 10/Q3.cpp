#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ch1("chapter1.txt"), ch2("chapter2.txt");
    ofstream book("book.txt", ios::app);

    string line;
    while (getline(ch1, line)) book << line << endl;
    book << endl;
    while (getline(ch2, line)) book << line << endl;

    ch1.close();
    ch2.close();
    book.close();

    ifstream showBook("book.txt");
    cout << "\nCombined Book:\n";
    while (getline(showBook, line)) {
        cout << line << endl;
    }
    showBook.close();
    return 0;
}
//self note:Tests reading from multiple files and appending contents to a single file.
