#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name, email, summary;
    int years;

    cout << "Enter Name, Email, Years of Experience, and Summary:\n";
    getline(cin, name);
    getline(cin, email);
    cin >> years;
    cin.ignore(); // flush newline
    getline(cin, summary);

    ofstream outFile("resume.txt", ios::trunc);
    outFile << "Name: " << name << "\nEmail: " << email << "\nExperience: " << years << " years\nSummary: " << summary << endl;
    outFile.close();

    // Display contents
    ifstream inFile("resume.txt");
    string line;
    cout << "\nResume File:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
