#include<iostream>
using namespace std;

class Square{
    float sideLength;
    float area;
    static float allareas;
    public:
Square():sideLength(0.0),area(0.0){}
Square(float sideLength){    
    this->sideLength=sideLength;
    Calculate_Area();
}
void set_Area(float a){
    this->area=a;
}
void setSidelength(float sl){
    this->sideLength=sl;
}
void Calculate_Area(){
    area = (this->sideLength)*(this->sideLength);
    this->allareas+=area;
}
static void setAllareas(float AA){
    allareas=AA;
}
float getarea(){return area;}
float getsidelenght(){return sideLength;}
static float getallareas(){return allareas;}

};
float Square::allareas=0.0;
int main(){
    float s1,s2,s3;
    cout<<"Enter the side Length 1: "<<endl;
    cin>> s1;
    Square a1(s1);
   
    cout << "Area of the square: " << a1.getarea() << endl;  
    cout << "Total area of all squares: " << Square::getallareas() << endl; 
    cout<<"Enter the side Length 2: "<<endl;
    cin>> s2;
    Square a2(s2);
    
    cout << "Area of the square: " << a2.getarea() << endl;  
    cout << "Total area of all squares: " << Square::getallareas() << endl; 
    cout<<"Enter the side Length 3: "<<endl;
    cin>> s3;
    Square a3(s3);
   
    cout << "Area of the square: " << a3.getarea() << endl;  
    cout << "Total area of all squares: " << Square::getallareas() << endl; 

}
