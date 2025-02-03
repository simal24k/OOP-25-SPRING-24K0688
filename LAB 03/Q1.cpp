#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time() : hours(0), minutes(0), seconds(0) {}

  
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        
        if (s >= 60) {
            minutes += s / 60;
            seconds = s % 60;
        }
        if (m >= 60) {
            hours += m / 60;
            minutes = m % 60;
        }
        if (hours >= 24) {
            hours = hours % 24;     
        }
    }

    
    void display() const {
        cout <<  hours << ":"
                  << minutes << ":"
                  << seconds << endl;
    }

    
    Time add(const Time &t1, const Time &t2) {
        int total_seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds +
                            t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

        int result_hours = (total_seconds / 3600) % 24;
        int result_minutes = (total_seconds % 3600) / 60;
        int result_seconds = total_seconds % 60;

        return Time(result_hours, result_minutes, result_seconds);
    }
};

int main() {
   
    const Time t1(11, 15, 50);  
    const Time t2(2, 20, 35);   
    Time t3;

    
    t3 = t3.add(t1, t2);


   t3.display();

    return 0;
}
