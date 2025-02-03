#include <iostream>
using namespace std;

class SerialNumber {
private:
    static int count;
    int serial;
public:
    SerialNumber() {
        serial = ++count;
    }
    void showSerial() const {
        cout << "I am object number " << serial << endl;
    }
};

int SerialNumber::count = 0;

int main() {
    SerialNumber ob1, ob2, ob3;
    ob2.showSerial();
    ob1.showSerial();
    ob3.showSerial();
    return 0;
}
