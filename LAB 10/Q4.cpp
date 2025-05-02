#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string text = "C++ is a powerful programming language.";
    ofstream fileOut("info.txt");
    fileOut << text;
    fileOut.close();

    fstream file("info.txt", ios::in | ios::out);
    cout << "Initial get pointer: " << file.tellg() << endl;
    cout << "Initial put pointer: " << file.tellp() << endl;

    file.seekg(6);
    string word;
    file >> word;
    cout << "Read word at position 6: " << word << endl;

    file.seekp(6);
    file << "dynamic"; // overwrite "powerful" (8 characters)

    cout << "New get pointer: " << file.tellg() << endl;
    cout << "New put pointer: " << file.tellp() << endl;
    file.close();

    ifstream readFile("info.txt");
    string updated;
    getline(readFile, updated);
    cout << "\nUpdated File Content:\n" << updated << endl;
    readFile.close();
    return 0;
}
//self note: Tests file pointer manipulation with seekg, seekp, tellg, tellp.
