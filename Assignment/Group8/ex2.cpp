#include <iostream>
#include <vector>
using namespace std;

// Define a Student structure
struct Student {
	int id;
    string name;
    int age;
    string grade;
};

// Function to insert a student
void insertStudent(vector<Student>& students) {\
	
    Student newStudent;
    cout << "Enter student id: ";
    cin >> newStudent.id;
    cout << "Enter student name: ";
    cin >> ws; // consume any leftover newline
    getline(cin, newStudent.name);

    cout << "Enter age: ";
    cin >> newStudent.age;

    cout << "Enter grade: ";
    cin >> ws;
    getline(cin, newStudent.grade);

    students.push_back(newStudent);
    cout << "Inserted: " << newStudent.name << ", Age: " << newStudent.age << ", Grade: " << newStudent.grade << endl;
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    cout << "\nStudent List:\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].id << ": " << students[i].name << ", Age: " << students[i].age
             << ", Grade: " << students[i].grade << endl;
    }
}

// Function to delete a student by index
void deleteStudentByIndex(vector<Student>& students, int index) {
    if (index >= 0 && index < students.size()) {
        cout << "Deleted: " << students[index].name << endl;
        students.erase(students.begin() + index);
    } else {
        cout << "Invalid index. Cannot delete." << endl;
    }
}

// Main function
int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Insert student\n";
        cout << "2. Display all students\n";
        cout << "3. Delete student by index\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            insertStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            int index;
            cout << "Enter index to delete: ";
            cin >> index;
            deleteStudentByIndex(students, index);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

