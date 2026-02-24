#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) :hours(h), minutes(m), seconds(s) {}
    int toSeconds() {
        return hours * 3600 + minutes * 60 + seconds;
    }
    // Friend functions to compute the difference between two times
    friend int computeSecondsBetween( Time& t1,  Time& t2);
    friend int computeMinutesBetween( Time& t1,  Time& t2);
    friend int computeHoursBetween(Time& t1,Time& t2);

    // Display time
    void display() {
        cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }
};

// Compute the number of seconds between two times
int computeSecondsBetween( Time& t1, Time& t2) {
    return (t1.toSeconds() - t2.toSeconds());
}

// Compute the number of minutes between two times
int computeMinutesBetween( Time& t1,  Time& t2) {
    return computeSecondsBetween(t1, t2) / 60;
}

// Compute the number of hours between two times
int computeHoursBetween(Time& t1, Time& t2) {
    return computeSecondsBetween(t1, t2) / 3600;
}

int main() {
    int h1, m1, s1, h2, m2, s2;

    // Input first time
    cout << "Enter first time (hours minutes seconds): ";
    cin >> h1 >> m1 >> s1;
    Time time1(h1, m1, s1);

    // Input second time
    cout << "Enter second time (hours minutes seconds): ";
    cin >> h2 >> m2 >> s2;
    Time time2(h2, m2, s2);

    // Display the times
    cout << "First Time: ";
    time1.display();
    cout << "Second Time: ";
    time2.display();

    // Compute and display the differences
    cout << "Seconds between the two times: " << computeSecondsBetween(time1, time2) << " seconds" << endl;
    cout << "Minutes between the two times: " << computeMinutesBetween(time1, time2) << " minutes" << endl;
    cout << "Hours between the two times: " << computeHoursBetween(time1, time2) << " hours" << endl;

    return 0;
}
