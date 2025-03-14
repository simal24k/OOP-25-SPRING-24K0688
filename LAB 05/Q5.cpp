#include <iostream>
using namespace std;

class Engine {
    string model;
public:
    Engine(string model = "V6") : model(model) {}
    void displayEngine() const { cout << "Engine Model: " << model << endl; }
};

class Wheel {
    int diameter;
public:
    Wheel(int diameter = 16) : diameter(diameter) {}
    void displayWheel() const { cout << "Wheel Diameter: " << diameter << " inches" << endl; }
};

class Headlight {
    string kind;
public:
    Headlight(string kind = "LED") : kind(kind) {}
    void displayHeadlight() const { cout << "Headlight Kind: " << kind << endl; }
};

class Steering {
    string style;
public:
    Steering(string style = "Power") : style(style) {}
    void displaySteering() const { cout << "Steering Style: " << style << endl; }
};

class Car {
    Engine* motor;
    Wheel tires[4]; 
    Headlight lamps[2]; 
    Steering steer; 
    
public:
    Car(Engine* mot, int tireSize = 16, string lampType = "LED", string steerType = "Power") 
        : motor(mot), steer(steerType) {
        for (int i = 0; i < 4; i++) tires[i] = Wheel(tireSize);
        for (int i = 0; i < 2; i++) lamps[i] = Headlight(lampType);
    }
    void displayCarInfo() const {
        cout << "\nCar Info:\n";
        motor->displayEngine();
        for (int i = 0; i < 4; i++) tires[i].displayWheel();
        for (int i = 0; i < 2; i++) lamps[i].displayHeadlight();
        steer.displaySteering();
    }

    ~Car() { delete motor; }
};

int main() {
    Engine* carEngine = new Engine("V8"); 
    Car myVehicle(carEngine, 18, "Halogen", "Manual");

    myVehicle.displayCarInfo();

    return 0;
}
