// Q5. You're building a tool to search and replace a specific word in a text file without
// rewriting the entire file.
// Requirements:

// 1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
// future. AI will transform the world. Embrace AI now.)
// 2. Prompt the user to enter:
// ○ A searchWord (e.g., "AI")
// ○ A replacementWord (e.g., "ML")
// 3. Open the file using fstream in ios::in | ios::out mode.
// 4. Search for the searchWord using seekg() and read sequentially.
// 5. When found:
// ○ Use tellg() to get the current read pointer location.
// ○ Use seekp() to position the write pointer.
// ○ Replace the word only if the replacement is of equal or smaller length to
// avoid shifting content.

// 6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
// "XX").
// 7. After all replacements, display the updated file.
#include <iostream>
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
