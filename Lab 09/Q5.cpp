#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity {
    double distance, time;
public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() override {
        return (distance / time) * 60 * 1.036;
    }
};

class Cycling : public Activity {
    double speed, time;
public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() override {
        return speed * time * 8.5;
    }
};

// selfntee: tests Abstraction and polymorphism for flexible activity-specific calorie tracking system.
