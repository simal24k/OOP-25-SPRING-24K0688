include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("data.txt", ios::in | ios::out | ios::trunc);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    file << "AI is the future. AI will transform the world. Embrace AI now.";
    file.close();

    string searchWord, replacementWord;
    cout << "Enter the word to search: ";
    cin >> searchWord;
    cout << "Enter the word to replace with: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word is longer than search word. Exiting." << endl;
        return 1;
    }

    file.open("data.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file for reading and writing." << endl;
        return 1;
    }

    char ch;
    string buffer;
    while (file.get(ch)) {
        buffer += ch;
        if (buffer.size() > searchWord.size()) {
            buffer.erase(0, 1); // keep only last n characters
        }

        if (buffer == searchWord) {
            streampos pos = file.tellg(); // current read position
            file.seekp(pos - static_cast<streamoff>(searchWord.length()));

            file.write(replacementWord.c_str(), replacementWord.length());
            if (replacementWord.length() < searchWord.length()) {
                int padding = searchWord.length() - replacementWord.length();
                file.write(string(padding, ' ').c_str(), padding);
            }

            file.seekg(pos); // move read pointer back to after the replaced word
            buffer.clear();  // reset buffer
        }
    }
    file.close();

    // Display updated content
    ifstream inFile("data.txt");
    cout << "\nUpdated content of the file:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
//sself note:Tests in-place word replacement using file pointers and padding logic.
