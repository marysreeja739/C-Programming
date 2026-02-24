#include <iostream>
#include <string>
using namespace std;
void displayDate(int day, int month, int year) {
    cout << "Date: " <<day << "-"<<month << "-" << year << endl;
}
string getDaySuffix(int day) {
    if (day % 10 == 1 && day != 11) {
        return "st";
    } else if (day % 10 == 2 && day != 12) {
        return "nd";
    } else if (day % 10 == 3 && day != 13) {
        return "rd";
    } else {
        return "th";
    }
}

// Function to display date in ddth MON, yyyy format
void displayDate(int day, string month, int year) {
    string suffix = getDaySuffix(day);
    cout << "Date: " << day << suffix << " " << month << ", " << year << endl;
}

int main() {
    int date, month, year;
    string monthStr;

    // Get date for dd-mm-yyyy format from user
    cout << "Enter day (1-31): ";
    cin >> date;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cout<<"Enter the month name: ";
    cin>>monthStr;
    if(date<=31&&date>0&&month<=12&&month>0&&year>0)
    {
       displayDate(date, monthStr, year);
       displayDate(date, month,year);
    }
    return 0;
}
