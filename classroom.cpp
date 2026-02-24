#include<iostream>
#include<string>
using namespace std;

class classRoom {
private:
    string name;
    string roll;
    int *marks;
    static int count;
public:
    // Empty constructor
    classRoom() {
        name = "";
        roll = "";
        marks = new int[5];  // Dynamically allocate memory for marks
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;  // Initialize marks with zeros
        }
        count++;
    }

    // Default constructor
    classRoom(string n, string r) {
        name = n;
        roll = r;
        marks = new int[5];  // Dynamically allocate memory for marks
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;  // Initialize marks with zeros
        }
        count++;
    }

    // Parameterized constructor with marks array (pass by pointer)
    classRoom(string n, string r, const int *m) {
        name = n;
        roll = r;
        marks = new int[5];  // Dynamically allocate memory for marks
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];  // Copy marks from the passed array
        }
        count++;
    }

    // Constructor that takes an array of marks (pass by pointer)
    classRoom(const int *m) {
        name = "kavya";
        roll = "2";
        marks = new int[5];  // Dynamically allocate memory for marks
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];  // Copy marks from the passed array
        }
        count++;
    }

    // Copy constructor
    classRoom(classRoom &o) {
        name = o.name;
        roll = o.roll;
        marks = new int[5];  // Dynamically allocate memory for marks
        for (int i = 0; i < 5; i++) {
            marks[i] = o.marks[i];  // Copy marks from the other object
        }
        count++;
    }

    // Destructor
    ~classRoom() {
        delete[] marks;  // Free the dynamically allocated memory
        count--;
        cout << "Destructor called" << endl;
    }

    // Static function to get the count of objects
    static int getcount() {
        return count;
    }

    // Display function to print the object details
    void display()const {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int classRoom::count = 0;

int main() {
    // Marks array for initialization
    int marks1[5] = {10, 20, 30, 40, 50};
    int marks2[5] = {30, 70, 60, 80, 90};

    // Initializing array of objects with different constructors
    classRoom *classes= new classRoom[5];
    classes[0]=classRoom();                         // Empty constructor
    classes[1]=classRoom("sreeja", "23bit043");     // Default constructor
    classes[2]=classRoom(marks1);                   // Constructor with marks array
    classes[3]=classRoom("Devi", "23bit050", marks2);  // Parameterized constructor with marks array
    classes[4]=classRoom(classes[3]);                // Copy constructor

    // Displaying object details
    for (int i = 0; i < 5; i++) {
        cout << "Classroom " << i+1 << " details:" << endl;
        classes[i].display();
        cout << endl;
    }

    cout << "The total number of objects: " << classRoom::getcount() << endl;
    delete[] classes;
    // No need for `delete[]` here as the array is allocated on the stack, not the heap
    return 0;
}
