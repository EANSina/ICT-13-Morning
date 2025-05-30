ចាស! ខាងក្រោមនេះគឺជាកូដ C++ សម្រាប់ **Insert (បញ្ចូល) និស្សិតថ្មី** ដោយប្រើបច្ចេកវិទ្យា OOP (`Class`, `Object`, `Encapsulation`)។

---

### ✅ **កូដសម្រាប់ Insert និស្សិតថ្មី**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    float score;

public:
    Student(int i, string n, float s) {
        id = i;
        name = n;
        score = s;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Score: " << score << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void insertStudent(int id, string name, float score) {
        Student newStudent(id, name, score);
        students.push_back(newStudent);
        cout << "✅ Student inserted successfully.\n";
    }

    void showAllStudents() {
        if (students.empty()) {
            cout << "📭 No students available.\n";
            return;
        }
        for (int i = 0; i < students.size(); i++) {
            cout << "Student " << i + 1 << ": ";
            students[i].display();
        }
    }
};

int main() {
    StudentManager manager;
    int id;
    string name;
    float score;
    char choice;

    do {
        cout << "\n📥 Insert New Student:\n";
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Score: ";
        cin >> score;

        manager.insertStudent(id, name, score);

        cout << "\n📋 Current Student List:\n";
        manager.showAllStudents();

        cout << "\nDo you want to insert another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
```

---

### 🔎 ពន្យល់:

| ផ្នែក               | សារៈសំខាន់                                    |
| ------------------- | --------------------------------------------- |
| `Student`           | ថ្នាក់តំណាងឲ្យនិស្សិត (មាន id, name, score)   |
| `StudentManager`    | ថ្នាក់ដែលគ្រប់គ្រងបញ្ជីនិស្សិត                |
| `insertStudent()`   | មុខងារដើម្បីបញ្ចូលនិស្សិតថ្មីទៅក្នុង vector   |
| `showAllStudents()` | បង្ហាញនិស្សិតទាំងអស់ក្រោយពេលបញ្ចូល            |
| `main()`            | ទទួល input ពីអ្នកប្រើ និងហៅ `insertStudent()` |

---

ចង់ឲ្យខ្ញុំបន្ថែម input validation, ការពិនិត្យ `id` ស្ទួន, ឬផ្លាស់ប្តូរជា menu style មែនទេ?
