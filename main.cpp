#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Function prototypes
void addStudent(vector<Student>& students);
void viewStudents(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void searchStudent(const vector<Student>& students);
void saveToFile(const vector<Student>& students);
void loadFromFile(vector<Student>& students);

// Main function
int main() {
    vector<Student> students;
    loadFromFile(students);
    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Search Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                searchStudent(students);
                break;
            case 6:
                saveToFile(students);
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student course: ";
    cin.ignore();
    getline(cin, student.course);
    students.push_back(student);
    cout << "Student added successfully!\n";
}

// Function to view all students
void viewStudents(const vector<Student>& students) {
    cout << "\nList of Students:\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name
             << ", Age: " << student.age << ", Course: " << student.course << '\n';
    }
}

// Function to update student details
void updateStudent(vector<Student>& students) {
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;
    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new age: ";
            cin >> student.age;
            cout << "Enter new course: ";
            cin.ignore();
            getline(cin, student.course);
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Function to delete a student
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Function to search for a student
void searchStudent(const vector<Student>& students) {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;
    for (const auto& student : students) {
        if (student.id == id) {
            cout << "ID: " << student.id << ", Name: " << student.name
                 << ", Age: " << student.age << ", Course: " << student.course << '\n';
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Function to save students to a file
void saveToFile(const vector<Student>& students) {
    ofstream outFile("students.txt");
    for (const auto& student : students) {
        outFile << student.id << '\n'
                << student.name << '\n'
                << student.age << '\n'
                << student.course << '\n';
    }
    outFile.close();
}

// Function to load students from a file
void loadFromFile(vector<Student>& students) {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No data file found. Starting with an empty list.\n";
        return;
    }

    Student student;
    while (inFile >> student.id) {
        inFile.ignore();
        getline(inFile, student.name);
        inFile >> student.age;
        inFile.ignore();
        getline(inFile, student.course);
        students.push_back(student);
    }
    inFile.close();
}
