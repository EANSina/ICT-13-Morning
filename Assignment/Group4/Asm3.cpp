#include <iostream>
#include <string>
using namespace std;

// Student structure
  struct Student {
    int id;
    string name;
    float grade;
    int age;
};

// Function to display all students in array
void displayStudents(Student students[], int size) {
    cout << "\n=== Student List ===" << endl;
    cout << "ID\tName\t\tGrade\tAge" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" 
             << students[i].grade << "\t" << students[i].age << endl;
    }
}

// Function to add a new student to array
void addStudent(Student students[], int &size, int maxSize) {
    if (size >= maxSize) {
        cout << "Array is full! Cannot add more students." << endl;
        return;
    }
    
    cout << "\n=== Add New Student ===" << endl;
    cout << "Enter student ID: ";
    cin >> students[size].id;
    cout << "Enter student name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, students[size].name);
    cout << "Enter student grade: ";
    cin >> students[size].grade;
    cout << "Enter student age: ";
    cin >> students[size].age;
    
    size++;
    cout << "Student added successfully!" << endl;
}

// Function to delete student by index
void deleteStudentByIndex(Student students[], int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index! Index should be between 0 and " << size-1 << endl;
        return;
    }
    
    cout << "Deleting student: " << students[index].name << endl;
    
    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        students[i] = students[i + 1];
    }
    
    size--;
    cout << "Student deleted successfully!" << endl;
}

// Function to search student by ID and return index
int searchStudentById(Student students[], int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == searchId) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to search student by name and return index
int searchStudentByName(Student students[], int size, string searchName) {
    for (int i = 0; i < size; i++) {
        if (students[i].name == searchName) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}
  // Function ?????????????????? index ?? array
void updateValueAtIndex(int Students[], int size, int index, int newValue) {
    if (index >= 0 && index < size) {
        Students[index] = newValue;
    } else {
     Students[index] = newValue;
    }
}


// Main function with example usage
int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int currentSize = 0;
    
    // Sample data
    students[0] = {101, "Sokha", 85.5, 20};
    students[1] = {102, "Dara", 92.0, 19};
    students[2] = {103, "Malis", 78.5, 21};
    currentSize = 3;
    
    int choice;
    do {
        cout << "\n=== Student Management System ===" << endl;
        cout << "1. Display all students" << endl;
        cout << "2. Add new student" << endl;
        cout << "3. Delete student by index" << endl;
        cout << "4. Search student by ID" << endl;
        cout << "5. Search student by name" << endl;
        cout << "6. update Value Student "<< endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayStudents(students, currentSize);
                break;
                
            case 2:
                addStudent(students, currentSize, MAX_STUDENTS);
                break;
                
            case 3: {
                int index;
                cout << "Enter index to delete (0 to " << currentSize-1 << "): ";
                cin >> index;
                deleteStudentByIndex(students, currentSize, index);
                break;
            }
            
            case 4: {
                int searchId;
                cout << "Enter student ID to search: ";
                cin >> searchId;
                int index = searchStudentById(students, currentSize, searchId);
                if (index != -1) {
                    cout << "Student found at index " << index << ":" << endl;
                    cout << "ID: " << students[index].id << ", Name: " << students[index].name 
                         << ", Grade: " << students[index].grade << ", Age: " << students[index].age << endl;
                } else {
                    cout << "Student with ID " << searchId << " not found!" << endl;
                }
                break;
            }
            
            case 5: {
                string searchName;
                cout << "Enter student name to search: ";
                cin.ignore();
                getline(cin, searchName);
                int index = searchStudentByName(students, currentSize, searchName);
                if (index != -1) {
                    cout << "Student found at index " << index << ":" << endl;
                    cout << "ID: " << students[index].id << ", Name: " << students[index].name 
                         << ", Grade: " << students[index].grade << ", Age: " << students[index].age << endl;
                } else {
                    cout << "Student with name \"" << searchName << "\" not found!" << endl;
                }
                break;
            }
            case 6: {
            	
////    int size = sizeof(Students) / sizeof(Students[0]);
//
//    cout << "Before update: ";
//    for (int i = 0; i < size; i++) {
//        cout <<Student[i]<< " ";
//    }
//    cout << endl;
//
//    // ????????? index 2 ???? 99
//    updateValueAtIndex(Students, size, 2, 99);
//
//    cout << "After update: ";
//    for (int i = 0; i < size; i++) {
////        cout << Students[i] << " ";
//    }
//    cout << endl;

				break;
			}

			
            case 0:
                cout << "Thank you for using Student Management System!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}

