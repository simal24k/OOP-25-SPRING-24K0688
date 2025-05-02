#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

void writeInitialRecords(int count) {
    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    Student students[5];
    cout << "Enter data for " << count << " students:\n";
    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "GPA: ";
        cin >> students[i].gpa;

        outFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }

    outFile.close();
    cout << "\nInitial records saved successfully.\n";
}

// Function to append a new student record
void appendRecord() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    Student s;
    cout << "\nEnter data for an additional student:\n";
    cout << "ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, s.name);
    cout << "GPA: ";
    cin >> s.gpa;

    outFile << s.id << " " << s.name << " " << s.gpa << endl;
    outFile.close();
    cout << "New student record appended successfully.\n";
}

void displayRecords() {
    ifstream inFile("students.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Student s;
    cout << "\n--- All Student Records ---\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(5) << "GPA" << endl;
    cout << "-----------------------------------\n";

    while (inFile >> s.id >> s.name >> s.gpa) {
        cout << left << setw(10) << s.id
             << setw(20) << s.name
             << setw(5) << s.gpa << endl;
    }

    inFile.close();
}

int main() {
    writeInitialRecords(5);
    appendRecord();
    displayRecords();

    return 0;
}
//self note:Tests struct usage and basic file operations (write, append, read).
