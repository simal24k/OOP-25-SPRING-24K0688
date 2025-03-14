#include <iostream>
#include <string>
using namespace std;

class ValidateString {
    string myString;

public:
    ValidateString(string str = "hello") : myString(str) {}

    bool isValid() const {
        for (char ch : myString) {
            if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString str1("dog"), str2("cat123"), str3("hello_world");

    cout << "str1 (dog) is " << (str1.isValid() ? "good" : "nope") << endl;
    cout << "str2 (cat123) is " << (str2.isValid() ? "good" : "nope") << endl;
    cout << "str3 (hello_world) is " << (str3.isValid() ? "good" : "nope") << endl;

    return 0;
}
