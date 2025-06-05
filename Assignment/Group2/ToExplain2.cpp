#include <iostream>
#include <string>
using namespace std;

void studentArrayOperations() {
    const int SIZE = 5;
    string students[SIZE] = {"Panha", "Penh", "P.didty", "Som", "drake"};
    
    // 1. Print all students
    cout << "All students: ";
    for(int i = 0; i < SIZE; i++) {
        cout << students[i] << " ";
    }
    cout << endl;
    
    // 2. Find a student by name
    string searchName = "P.diddty";
    bool found = false;
    for(int i = 0; i < SIZE; i++) {
        if(students[i] == searchName) {
            cout << "Found " << searchName << " at index " << i << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << searchName << " not found in array" << endl;
    }
    
    // 3. Get student by index
    int index = 2;
    if(index >= 0 && index < SIZE) {
        cout << "Student at index " << index << ": " << students[index] << endl;
    } else {
        cout << "Invalid index" << endl;
    }
    
    // 4. Update student name by index
    index = 3;
    string newName = "Sim";
    if(index >= 0 && index < SIZE) {
        students[index] = newName;
        cout << "Updated student at index " << index << " to " << newName << endl;
    } else {
        cout << "Invalid index for update" << endl;
    }
    
    // 5. Print updated array
    cout << "Updated student list: ";
    for(int i = 0; i < SIZE; i++) {
        cout << students[i] << " ";
    }
    cout << endl;
}

int main() {
    studentArrayOperations();
    return 0;
}

