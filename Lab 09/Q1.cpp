#include<iostream>
using namespace std;

class Vehicle{
protected:
string model;
double rate;

public:
Vehicle(string m, double r){
    this->model=m;
    this->rate=r;
}
virtual double getDailyRate()=0; 
virtual void displayDetails()=0; 
};

class Car: public Vehicle{
public:
Car(string m, double r): Vehicle(m,r){}

double getDailyRate() override{
    return rate;
}
void displayDetails() override{
    cout<<"---Car Details---"<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Daily Rate: "<<rate<<endl;
}
};

class Bike: public Vehicle{
    public:
    Bike(string m, double r): Vehicle(m,r){}
double getDailyRate() override{
    return rate;
}
void displayDetails() override{
    cout<<"---Bike Details---"<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Daily Rate: "<<rate<<endl;
}
};

int main(){
    Car c("718 Cayman Style Edition", 5000000.0);
    Bike b("Yamaha YZF R1", 450000.00);
    c.displayDetails();
    b.displayDetails();

    cout<<"Daily rate of car: "<<c.getDailyRate()<< endl;
    cout<<"Daily rate of bike: "<<b.getDailyRate()<< endl;
}

