#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    virtual void Salary()
    {
        cout << "Employee Salary with string info" << endl;
    }
};
class PermanentEmployee : public Employee
{
public:
    string designation;
    PermanentEmployee(string d)
    {
       designation=d;
    }
    void Salary() {
        if (designation == "Manager") {
            cout << "Manager's Salary: 70,000 INR" << endl;
        } else if (designation == "Developer") {
            cout << "Developer's Salary: 50,000 INR" << endl;
        } else {
            cout << "Other Permanent Employee's Salary: 40,000 INR" << endl;
        }
    }
};
class DailyWageEmployee : public Employee
{
public:
    int hoursWorked;
    DailyWageEmployee(int h)
    {
       hoursWorked=h;
    }
    void Salary() {
        cout << "Daily Wage Employee's Salary: " << hoursWorked * 500 << " INR" << endl;
    }
};
int main()
{
    PermanentEmployee permEmp("Manger");
    DailyWageEmployee dailyEmp(8);
    Employee *e1 = &permEmp;
    Employee *e2 = &dailyEmp;
    e1->Salary();
    e2->Salary();
    return 0;
}
