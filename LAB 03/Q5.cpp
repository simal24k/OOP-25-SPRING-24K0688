#include <iostream>
using namespace std;

class Planner {
private:
    string janTasks[31];
    string febTasks[29];
    string marTasks[31];
    string aprTasks[30];
    string mayTasks[31];
    string junTasks[30];
    string julTasks[31];
    string augTasks[31];
    string sepTasks[30];
    string octTasks[31];
    string novTasks[30];
    string decTasks[31];
    int currentYear;

    string* getMonthData(string month, int& totalDays) {
        if (month == "January") {
            totalDays = 31;
            return janTasks;
        } else if (month == "February") {
            totalDays = 29;
            return febTasks;
        } else if (month == "March") {
            totalDays = 31;
            return marTasks;
        } else if (month == "April") {
            totalDays = 30;
            return aprTasks;
        } else if (month == "May") {
            totalDays = 31;
            return mayTasks;
        } else if (month == "June") {
            totalDays = 30;
            return junTasks;
        } else if (month == "July") {
            totalDays = 31;
            return julTasks;
        } else if (month == "August") {
            totalDays = 31;
            return augTasks;
        } else if (month == "September") {
            totalDays = 30;
            return sepTasks;
        } else if (month == "October") {
            totalDays = 31;
            return octTasks;
        } else if (month == "November") {
            totalDays = 30;
            return novTasks;
        } else if (month == "December") {
            totalDays = 31;
            return decTasks;
        } else {
            totalDays = 0;
            return nullptr;
        }
    }

public:
    Planner(int year) {
        currentYear = year;
    }

    void insertTask(string taskDetail, int day, string month) {
        int totalDays;
        string* monthData = getMonthData(month, totalDays);

        if (!monthData || day < 1 || day > totalDays) {
            cout << "Invalid date or month!" << endl;
            return;
        }

        monthData[day - 1] = taskDetail;
        cout << "Task added on " << month << " " << day << ": " << taskDetail << endl;
    }

    void deleteTask(int day, string month) {
        int totalDays;
        string* monthData = getMonthData(month, totalDays);

        if (!monthData || day < 1 || day > totalDays) {
            cout << "Invalid date or month!" << endl;
            return;
        }

        monthData[day - 1] = "";
        cout << "Task removed from " << month << " " << day << endl;
    }

    void displayTasks() {
        cout << "\n=== Task List for Year " << currentYear << " ===\n";

        string months[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

        for (int i = 0; i < 12; i++) {
            int totalDays;
            string* monthData = getMonthData(months[i], totalDays);

            for (int d = 0; d < totalDays; d++) {
                if (!monthData[d].empty()) {
                    cout << months[i] << " " << d + 1 << ": " << monthData[d] << endl;
                }
            }
        }
    }
};

int main() {
    Planner myPlanner(2025);

    myPlanner.insertTask("Order Lasagna", 15, "January");
    myPlanner.insertTask("Team Meeting - NX", 22, "April");
    myPlanner.insertTask("Frenniversay", 4, "February");
    myPlanner.insertTask("Project deadline", 8, "May");
    myPlanner.insertTask("Submission", 25, "December");

    myPlanner.displayTasks();

    myPlanner.deleteTask(25, "December");

    cout << "\nUpdated task list:\n";
    myPlanner.displayTasks();

    return 0;
}
