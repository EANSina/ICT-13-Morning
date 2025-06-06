#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

// Parallel arrays
string names[MAX];
string genders[MAX];
int ages[MAX];

int count = 0;

// View all students
void viewStudents() {
    if (count == 0) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". Name: " << names[i]
             << ", Gender: " << genders[i]
             << ", Age: " << ages[i] << endl;
    }
}

// Add new student
void addNewStudent() {
    if (count >= MAX) {
        cout << "Student list is full.\n";
        return;
    }

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, names[count]);

    cout << "Enter gender: ";
    getline(cin, genders[count]);

    cout << "Enter age: ";
    cin >> ages[count];

    count++;
    cout << "Student added.\n";
}

// Edit student
void editStudent() {
    int number;
    viewStudents();
    cout << "Enter student number to edit: ";
    cin >> number;

    if (number < 1 || number > count) {
        cout << "Invalid number.\n";
        return;
    }

    cin.ignore();
    cout << "Enter new name: ";
    getline(cin, names[number - 1]);

    cout << "Enter new gender: ";
    getline(cin, genders[number - 1]);

    cout << "Enter new age: ";
    cin >> ages[number - 1];

    cout << "Student updated.\n";
}

// Find student
void findStudent() {
    string searchName;
    cin.ignore();
    cout << "Enter name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (names[i] == searchName) {
            cout << "Found: " << names[i]
                 << ", " << genders[i]
                 << ", " << ages[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

// Delete student
void deleteStudent() {
    int number;
    viewStudents();
    cout << "Enter student number to delete: ";
    cin >> number;

    if (number < 1 || number > count) {
        cout << "Invalid number.\n";
        return;
    }

    for (int i = number - 1; i < count - 1; i++) {
        names[i] = names[i + 1];
        genders[i] = genders[i + 1];
        ages[i] = ages[i + 1];
    }

    count--;
    cout << "Student deleted.\n";
}

int main() {
    // Sample data
    names[0] = "Senghong"; genders[0] = "Male"; ages[0] = 20;
    names[1] = "Nang";   genders[1] = "Male";   ages[1] = 19;
    names[2] = "Phop"; genders[2] = "Male"; ages[2] = 20;
    names[3] = "Phai";   genders[3] = "Male";   ages[3] = 20;
    names[4] = "Rotha";   genders[4] = "Female";   ages[4] = 20;
    count = 5;

    int choice;

    while (true) {
        cout << "\n--- Student Management ---\n";
        cout << "1. View All Students\n";
        cout << "2. Add New Student\n";
        cout << "3. Edit Student\n";
        cout << "4. Find Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewStudents(); break;
            case 2: addNewStudent(); break;
            case 3: editStudent(); break;
            case 4: findStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
