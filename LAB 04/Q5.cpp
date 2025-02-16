#include<iostream>
using namespace std;

class Worker {
    private:
    int workerID;
    string fullName;
    string division;
    double earnings;

    public:
    Worker(): earnings(0.0) {}
    Worker(int id, string name, string dept, double pay) {
        this->workerID = id;
        this->fullName = name;
        this->earnings = pay;
        this->division = dept;
    }

    void addIncentive(double extraPay) {
        earnings += extraPay;
        cout << "Incentive added" << endl;
    }
    
    bool checkManager() {
        return (this->division == "Management");
    }

    void showInfo() {
        cout << "Worker ID: " << this->workerID << endl;
        cout << "Full Name: " << this->fullName << endl;
        cout << "Division: " << division << endl;
        cout << "Earnings: " << this->earnings << endl;
        cout << "-----------------------" << endl << endl;
    }
};

int main() {
    Worker staff[3]{{113, "Saira", "Batool", 250000}, {109, "Fariha", "HR", 9000}, {120, "Alyana", "HR", 11000}};
    
    for(int i = 0; i < 3; i++) {
        if (staff[i].checkManager())
            staff[i].addIncentive(12000);
    }

    for(int i = 0; i < 3; i++) {
        staff[i].showInfo();
    }
    return 0;
}
