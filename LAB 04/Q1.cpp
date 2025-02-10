#include<iostream>
using namespace std;
class Student{
    private: 
    int studentID;
    string name;
    int age;
    char grade;

    public:
    Student(){
        grade='N';
    }
    Student(int studentID, string name, int age, char grade){
        this->studentID=studentID;
        this->name=name;
        this->age=age;
        this->grade=grade;
    }
    void promoteStudent(char grade){
        if(grade!='A'){
            this->grade=grade-1; /*from 'A' to 'B'*/
        }}
    bool EligibleForScholarship(){
        if(grade=='A'){
            return true;
        }
        else{
            return false;
        }
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Grade: "<<grade<<endl;
        if(EligibleForScholarship()){
            cout<<"Student is eligible for scholarship"<<endl;
        }
        else{
            cout<<"Student is not eligible for scholarship"<<endl;
        }
    }
};
int main(){
    Student std1(688, "Simal", 19, 'A');
    Student std2(1026, "Manahil", 19, 'B');
    Student std3(1010, "Fariha", 16, 'C');
    std1.display();
    std2.display();
    std3.display();
    return 0;

}
