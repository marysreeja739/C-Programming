#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string student_id;  // Changed to std::string
    string name;        // Changed to std::string

    // Constructor
    Student() {}

    // Declare the friend functions
    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);
};

// Define the >> operator outside the class
istream& operator>>(istream& in, Student& student) {
    cout << "Enter student ID: ";
    in >> student.student_id;
    cout << "Enter student name: ";
    in >> student.name;
    return in;
}

// Define the << operator outside the class
ostream& operator<<(ostream& out, const Student& student) {
    out << "Student ID: " << student.student_id << ", Name: " << student.name;
    return out;
}

class Course {
private:
    string course_name;    // Changed to std::string
    Student* students;     // Pointer to hold dynamically allocated array of students
    int student_count;
    int max_students;      // Maximum number of students allowed in the course

public:
    // Constructor with dynamic memory allocation
    Course(int max_students = 100) : student_count(0), max_students(max_students) {
        students = new Student[max_students];  // Dynamically allocate memory for students
    }

    // Destructor to release dynamically allocated memory
    ~Course() {
        delete[] students;  // Deallocate memory for the students array
    }

    // Declare the friend functions
    friend istream& operator>>(istream& in, Course& course);
    friend ostream& operator<<(ostream& out, const Course& course);

    // Overload + operator to enroll a student
    void operator+(const Student& student) {
        if (student_count < max_students) {
            students[student_count] = student;
            student_count++;
        } else {
            cout << "Cannot enroll more students. Course is full.\n";
        }
    }

    // Overload - operator to drop a student
    void operator-(const Student& student) {
        for (int i = 0; i < student_count; i++) {
            if (students[i].student_id == student.student_id) {
                for (int j = i; j < student_count - 1; j++) {
                    students[j] = students[j + 1];  // Shift students down
                }
                student_count--;
                cout << student.name << " has been dropped from the course.\n";
                return;
            }
        }
        cout << "Student not found in the course.\n";
    }

    // Compare courses by number of students
    bool hasMoreStudents(const Course& other) const {
        return student_count > other.student_count;
    }
};

// Define the >> operator outside the class
istream& operator>>(istream& in, Course& course) {
    cout << "Enter course name: ";
    in >> course.course_name;
    return in;
}

// Define the << operator outside the class
ostream& operator<<(ostream& out, const Course& course) {
    out << "Course Name: " << course.course_name << ", Students Enrolled: " << course.student_count << "\n";
    for (int i = 0; i < course.student_count; i++) {
        out << "\t" << course.students[i] << "\n";
    }
    return out;
}

int main() {
    // Create students
    Student s1, s2, s3;

    // Use >> operator to input student details
    cout << "Enter details for Student 1:\n";
    cin >> s1;

    cout << "Enter details for Student 2:\n";
    cin >> s2;

    cout << "Enter details for Student 3:\n";
    cin >> s3;

    // Create courses
    Course c1(50), c2(50);  // Dynamically allocate up to 50 students for each course

    // Input course names using >> operator
    cout << "Enter details for Course 1:\n";
    cin >> c1;

    cout << "Enter details for Course 2:\n";
    cin >> c2;

    // Enroll students in courses using + operator
    c1 + s1;
    c1 + s2;

    c2 + s3;

    // Print course details using << operator
    cout << "Course 1 details:\n" << c1;
    cout << "Course 2 details:\n" << c2;

    // Compare courses by number of students
    if (c1.hasMoreStudents(c2)) {
        cout << "Course 1 has more students than Course 2.\n";
    } else {
        cout << "Course 2 has more or equal students than Course 1.\n";
    }

    // Drop a student using - operator
    c1 - s2;

    cout << "After dropping a student from Course 1:\n";
    cout << c1;

    return 0;
}
