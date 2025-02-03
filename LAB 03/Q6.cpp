#include<iostream>
using namespace std;

class SPhone {
    private:
        string company;
        string model;
        string dprs;
        string RAM;
        string ROM;
        string storage;

    public:
       
        void set_company(string company) {
            this->company = company;
        }
        string get_company() {
            return company;
        }
        
        void set_model(string model) {
            this->model = model;
        }
        string get_model() {
            return model;
        }
        
        void set_dprs(string dprs) {
            this->dprs = dprs;
        }
        string get_dprs() {
            return dprs;
        }
        
        void set_RAM(string RAM) {
            this->RAM = RAM;
        }
        string get_RAM() {
            return RAM;
        }
        
        void set_ROM(string ROM) {
            this->ROM = ROM;
        }
        string get_ROM() {
            return ROM;
        }

        void set_storage(string storage) {
            this->storage = storage;
        }
        string get_storage() {
            return storage;
        }

     
        void display() {
            cout << "Company: " << get_company() << endl;
            cout << "Model: " << get_model() << endl;
            cout << "DPRS: " << get_dprs() << endl;
            cout << "RAM: " << get_RAM() << endl;
            cout << "ROM: " << get_ROM() << endl;
            cout << "Storage: " << get_storage() << endl;
        }

        
        void make_phone() {
            cout << "Making a call..." << endl;
        }

        void send_msg() {
            cout << "Sending a message..." << endl;
        }

        void connect_wifi(int i) {
            if (i == 1) {
                cout << "Connecting to wifi..." << endl;
            } else {
                cout << "Not connected - use cellular" << endl;
            }
        }

        void browser() {
            cout << "Most compatible browser is Chrome" << endl;
        }
};

int main() {
    SPhone s1;


    s1.set_company("Samsung");
    s1.set_model("Galaxy S23");
    s1.set_dprs("108 MP");
    s1.set_RAM("12 GB");
    s1.set_ROM("256 GB");
    s1.set_storage("512 GB");


    s1.display();
    
   
    int i = 1; 
    s1.connect_wifi(i);  
    s1.browser();

    return 0;
}
