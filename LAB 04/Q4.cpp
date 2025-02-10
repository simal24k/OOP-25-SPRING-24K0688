#include<iostream>
#include <conio.h>
using namespace std;

class Vehicle {
    private:
        int vehicleID;
        string vehicleModel;
        int manufacturingYear;
        bool isCurrentlyRented;

    public:
        Vehicle() : isCurrentlyRented(false) {}

        Vehicle(int vehicleID, string vehicleModel, int manufacturingYear, bool isCurrentlyRented) {
            this->vehicleID = vehicleID;
            this->vehicleModel = vehicleModel;
            this->manufacturingYear = manufacturingYear;
            this->isCurrentlyRented = isCurrentlyRented;
        }

        void rentVehicle() {
            if (isCurrentlyRented) {
                cout << "The Vehicle is already Rented" << endl;
            }
            else {
                isCurrentlyRented = true;
                cout << "Vehicle rented Successfully" << endl;
            }
        }

        void returnVehicle() {
            if (isCurrentlyRented) {
                isCurrentlyRented = false;
                cout << "Vehicle returned Successfully" << endl;
            }
            else {
                cout << "You did not rent a Vehicle" << endl;
            }
        }

        bool isClassic() {
            if (manufacturingYear < 2000) {
                cout << "The Vehicle is Classic" << endl;
                return true;
            }
            else {
                cout << "The Vehicle is not Classic" << endl;
                return false;
            }
        }
};

int main() {
    Vehicle v1 = Vehicle(819, "Mercedes", 2024, false);
    char userChoice;
    while (true) {
        cout << "What do you want to do\n1.Rent a Vehicle\n2.Return Vehicle\n3.Check if Classic\n4.Exit\n";
        userChoice = _getch();
        switch (userChoice) {
            case '1':
                v1.rentVehicle();
                break;
            case '2':
                v1.returnVehicle();
                break;
            case '3':
                v1.isClassic();
                break;
            case '4':
                cout << "Thank you for coming" << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
    return 0;
}
1
