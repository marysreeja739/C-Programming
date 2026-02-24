#include <iostream>
#include <string>
using namespace std;
class Employee {
public:
    virtual void compute_salary()
    {
       cout<<"EMPLOYEE CLASS";}
    virtual void display_details()
    {
       cout<<"DISPLAY EMPLOYEE CLASS";
    }
};
class PermanentEmployee : public Employee {
public:
    virtual void festival_bonus()
    {
       cout<<"Permanent employee festival bonus";}
};
class DailyWages : public Employee {
public:
    void compute_salary() {
        cout << "Computing salary for Daily Wages employee." << endl;
    }
    void display_details() {
        cout << "Displaying details of Daily Wages employee." << endl;
    }
};
class Departmental : public PermanentEmployee
{
    void compute_salary() {
        cout << "Computing salary for Departmental." << endl;
    }
    void display_details() {
        cout << "Displaying details of Departmental." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Departmental." << endl;
    }
};
class Company : public PermanentEmployee
{
    void compute_salary() {
        cout << "Computing salary for Company." << endl;
    }
    void display_details() {
        cout << "Displaying details of Company." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Company." << endl;
    }

};
class RegionalManager : public Company {
public:
    void compute_salary() {
        cout << "Computing salary for Regional Manager." << endl;
    }
    void display_details() {
        cout << "Displaying details of Regional Manager." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Regional Manager." << endl;
    }
};

class AreaManager : public Company {
public:
    void compute_salary() {
        cout << "Computing salary for Area Manager." << endl;
    }
    void display_details() {
        cout << "Displaying details of Area Manager." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Area Manager." << endl;
    }
};
class HumanResource : public Departmental {
public:
    void compute_salary() {
        cout << "Computing salary for Human Resource employee." << endl;
    }
    void display_details() {
        cout << "Displaying details of Human Resource employee." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Human Resource employee." << endl;
    }
};

class Production : public Departmental {
public:
    void compute_salary() {
        cout << "Computing salary for Production employee." << endl;
    }
    void display_details() {
        cout << "Displaying details of Production employee." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Production employee." << endl;
    }
};

class Sales : public Departmental {
public:
    void compute_salary() {
        cout << "Computing salary for Sales employee." << endl;
    }
    void display_details() {
        cout << "Displaying details of Sales employee." << endl;
    }
    void festival_bonus() {
        cout << "Calculating festival bonus for Sales employee." << endl;
    }
};

int main() {
    RegionalManager regManager;
    DailyWages dailyWorker;
    HumanResource hrEmployee;
    Employee ptr;
    regManager.compute_salary();
    regManager.display_details();
    if (PermanentEmployee* p = dynamic_cast<PermanentEmployee*>(&regManager)) {
        p->festival_bonus();
    }
    Employee *pt=&ptr;
    DailyWages *d = dynamic_cast<DailyWages*>(pt);
    if(d)
       d->compute_salary();
    else
    {
       cout<<"NULL not casted properly\n";}
    dailyWorker.compute_salary();
    dailyWorker.display_details();

    hrEmployee.compute_salary();
    hrEmployee.display_details();
    if (PermanentEmployee* p = dynamic_cast<PermanentEmployee*>(&hrEmployee)) {
        p->festival_bonus();
    }

    return 0;
}
