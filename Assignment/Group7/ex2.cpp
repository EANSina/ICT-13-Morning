#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
string Students[MAX];
int studentCount = 0;

// Function to input student names into the array
void inputStudents() {
    cout << "Enter number of students to add: ";
    int n;
    cin >> n;
    cin.ignore(); // Clear newline from input buffer

    for (int i = 0; i < n; ++i) {
        if (studentCount >= MAX) {
            cout << "Array is full. Cannot add more students.\n";
            break;
        }
        cout << "Enter name of student " << studentCount + 1 << ": ";
        getline(cin, Students[studentCount]);
        studentCount++;
    }
}

// Function to display all student names
void displayStudents() {
    if (studentCount == 0) {
        cout << "No students in the list.\n";
        return;
    }
    cout << "\nStudent List:\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << i << ": " << Students[i] << endl;
    }
}

// Function to search for a name and return the index
int searchStudent(string name) {
    for (int i = 0; i < studentCount; ++i) {
        if (Students[i] == name) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to delete a student by name
void deleteStudent() {
    string name;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, name);

    int index = searchStudent(name);
    if (index != -1) {
        for (int i = index; i < studentCount - 1; ++i) {
            Students[i] = Students[i + 1];
        }
        --studentCount;
        cout << "Deleted " << name << " from the list.\n";
    } else {
        cout << name << " not found.\n";
    }
}

// Function to update a student's name
void updateStudent() {
    string oldName, newName;
    cout << "Enter name to update: ";
    cin.ignore();
    getline(cin, oldName);

    int index = searchStudent(oldName);
    if (index != -1) {
        cout << "Enter new name: ";
        getline(cin, newName);
        Students[index] = newName;
        cout << "Updated successfully.\n";
    } else {
        cout << oldName << " not found.\n";
    }
}

// Function to search and show index
void searchStudentByName() {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    int index = searchStudent(name);
    if (index != -1)
        cout << name << " found at index " << index << ".\n";
    else
        cout << name << " not found.\n";
}

// Main menu function
void menu() {
    int choice;
    do {
        cout << "\n=== Student Management Menu ===\n";
        cout << "1. Input Students\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputStudents();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudentByName();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
