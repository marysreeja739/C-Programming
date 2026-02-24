#include <iostream>
using namespace std;
template <typename T>
double calculateAverage(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}
template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                 T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
class Employee {
public:
    string name;
    int experience;
    double salary;
    Employee(string n = "", int exp = 0, double sal = 0.0) :
        name(n), experience(exp), salary(sal) {}
        bool operator>(const Employee& other) const {
        return experience > other.experience;
    }
    friend ostream& operator<<(ostream& os, const Employee& emp);
};
ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Name: " << emp.name << ", Experience: " << emp.experience
       << ", Salary: " << emp.salary;
    return os;
}
template <>
double calculateAverage<Employee>(Employee arr[], int size) {
    double totalSalary = 0;
    for (int i = 0; i < size; i++) {
        totalSalary += arr[i].salary;
    }
    return totalSalary / size;
}

int main() {
    int numSize;
    cout << "Enter the number of elements: ";
    cin >> numSize;

    int numbers[numSize];
    cout << "Enter the elements:\n";
    for (int i = 0; i < numSize; ++i) {
        cin >> numbers[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < numSize; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    double average = calculateAverage(numbers, numSize);
    cout << "Average: " << average << endl;

    sortArray(numbers, numSize);
    cout << "Sorted array: ";
    for (int i = 0; i < numSize; i++) {
        cout << numbers[i] << " ";
    }
    int empSize;
    cout << "\nEnter the number of employees: ";
    cin >> empSize;
    Employee employees[empSize];
    for (int i = 0; i < empSize; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "Experience: ";
        cin >> employees[i].experience;
        cout << "Salary: ";
        cin >> employees[i].salary;
    }

    cout << "\nEmployee details before sorting:\n";
    for (int i = 0; i < empSize; i++) {
        cout << employees[i] << endl;
    }

    sortArray(employees, empSize);

    cout << "\nEmployee details after sorting by experience:\n";
    for (int i = 0; i < empSize; i++) {
        cout << employees[i] << endl;
    }

    double avgSalary = calculateAverage(employees, empSize);
    cout << "\nAverage salary of employees: " << avgSalary << endl;

    return 0;
}
