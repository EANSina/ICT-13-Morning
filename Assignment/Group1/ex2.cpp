#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5; // number of all students (can change if you needed)

// Function 1: Input all student names
void inputStudents(string students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter name of student " << (i + 1) << ": ";
        cin >> students[i];
    }
}

// Function 2: Show all student names
void displayAllStudents(string students[], int size) {
    cout << "All student names: ";
    for (int i = 0; i < size; i++) {
        cout << students[i] << " ";
    }
    cout << endl;
}

// Function 3: Update a student's name by index
void updateStudentName(string students[], int size, int index, const string& newName) {
    if (index >= 0 && index < size) {
        cout << "Updating student at index " << index << " from \"" << students[index] << "\" to \"" << newName << "\"." << endl;
        students[index] = newName;
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Function 4: Search for a student by name
void searchStudentByName(string students[], int size, const string& name) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i] == name) {
            cout << "Student \"" << name << "\" found at index " << i << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student \"" << name << "\" not found!" << endl;
    }
}

// Function 5: Show names by entering its index
void displayStudentByIndex(string students[], int size, int index) {
    if (index >= 0 && index < size) {
        cout << "Student at index " << index << ": " << students[index] << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

int main() {
    string students[SIZE];
    int index;
    string name, newName;

    // Input names
    inputStudents(students, SIZE);

    // Display all names
    displayAllStudents(students, SIZE);

    // --- Update comes first now ---
    cout << "Enter index to update student name (0 to " << SIZE - 1 << "): ";
    cin >> index;
    cout << "Enter new name: ";
    cin >> newName;
    updateStudentName(students, SIZE, index, newName);

    // Show the updated list
    displayAllStudents(students, SIZE);

    // --- Then search ---
    cout << "Enter a name to search: ";
    cin >> name;
    searchStudentByName(students, SIZE, name);

    // Show student by index
    cout << "Enter index to show student (0 to " << SIZE - 1 << "): ";
    cin >> index;
    displayStudentByIndex(students, SIZE, index);

    return 0;
}

