#include<iostream>
#include <conio.h>
using namespace std;

class Tollbooth {
private:
    unsigned int carCount;    
    double revenue;           

public:

    Tollbooth() : carCount(0), revenue(0){}

    
    void payingCar() {
        carCount++;
        revenue += 0.50;  
    }

   
    void nopayCar() {
        carCount++;  
    }

    void display() const {
        cout << "Total cars: " << carCount << endl;
        cout << "Total cash collected: $" << revenue << endl;
    }
};

int main() {
    Tollbooth tb;
    char charc;
    
    cout << "Please enter: \n 'p' for paying car \n 'n' for non-paying car \n Esc to exit " << endl;

    while (true) {
        charc = _getch();  
        if (charc == 27) 
            break;
        else if (charc == 'p' || charc == 'P') {
            tb.payingCar();  
            cout << "Paying car added." << endl;
        }
        else if (charc == 'n' || charc == 'N') {
            tb.nopayCar();  
            cout << "Non Paying car added." << endl;
        }
    }

    cout << "\n------ Tally ------\n";
    tb.display();  

    return 0;
}
