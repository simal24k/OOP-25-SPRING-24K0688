#include <iostream>
#include <iomanip>
using namespace std;

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int deg = 0, float min = 0.0, char dir = 'N') : degrees(deg), minutes(min), direction(dir) {}

    void getAngle()
    {
        cout << "Enter degrees: ";
        cin >> this->degrees;
        cout << "Enter minutes: ";
        cin >> this->minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> this->direction;
    }

    void displayAngle() const
    {
        cout << degrees << "\xF8" << fixed << setprecision(1) << minutes << "' " << direction << endl;
    }
};

int main()
{
    Angle angle(149, 34.8, 'W');

    angle.displayAngle();

    while (true)
    {
        angle.getAngle();
        angle.displayAngle();
        
        char choice;
        cout << "Do you want to enter another angle? (y/n): ";
        cin >> choice;

        if (tolower(choice) == 'n')
        {
            cout << "Program ended." << endl;
            break;
        }
    }

    return 0;
}
