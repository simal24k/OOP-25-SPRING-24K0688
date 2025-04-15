#include<iostream>
using namespace std;

class  SmartDevice{
public:

SmartDevice(){}
virtual void turnoff()=0;
virtual void turnon()=0;
virtual bool getStatus()=0;

virtual~SmartDevice(){}
};

class LightBulb: public SmartDevice{
    private:
    bool isOn;
    int brightness;
public:
LightBulb(bool on, int b){
    this->isOn=on;
    this->brightness=b;
}

void turnon() override{
    isOn = true;
    cout<<"Light is ON"<<endl;
}
void turnoff() override{
    isOn = false;
    cout<<"Light is OFF"<<endl;
}
bool getStatus () override {return isOn;}
};

class Thermostat: public SmartDevice{
    private:
bool isOn;
double temperature;
public:
Thermostat(bool n, double temp){
    this->isOn=n;
    this->temperature=temp;
}
void turnon() override{
    isOn = true;
    cout<<"Thermostat is ON"<<endl;
}
void turnoff() override{
    isOn = false;
    cout<<"Thermostat is OFF"<<endl;
}
bool getStatus () override {return isOn;}
};

int main(){
    LightBulb l1(true,85);
    Thermostat t1(false,10);
    t1.turnon();
    l1.turnoff();
    if(l1.getStatus()){
        cout<<"Light switch is off"<<endl;
    }
    if(t1.getStatus()){
        cout<<"Thermostat is on"<<endl;
    }

}
