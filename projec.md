ខាងក្រោមនេះជាលំហាត់មួយសម្រាប់បង្រៀននិស្សិតអំពី**Object-Oriented Programming (OOP) ក្នុងភាសា C++** ដែលរួមមាន៖

* ការបញ្ចូលតម្លៃ (Insert)
* ទាញតម្លៃ (Retrieve / Display)
* កែប្រែតម្លៃ (Update)
* ស្វែងរកតម្លៃ (Search)
* លុបតម្លៃ (Delete)

---

### 🔶 ចំណងជើងលំហាត់៖

**បង្កើតកម្មវិធីគ្រប់គ្រងបញ្ជីនិស្សិតប្រើ OOP ក្នុង C++**

### 🔸 ពិពណ៌នាលំហាត់៖

សូមបង្កើតថ្នាក់ (Class) `Student` ដែលមានព័ត៌មានដូចខាងក្រោម៖

* `id` (int)
* `name` (string)
* `score` (float)

បង្កើតមុខងារ (Methods) ក្នុង `StudentManager` ដែលអាចបញ្ចូលនិស្សិតថ្មី, បង្ហាញបញ្ជីនិស្សិតទាំងអស់, កែប្រែព័ត៌មាននិស្សិតតាម `id`, ស្វែងរកនិស្សិតតាម `id`, និងលុបនិស្សិតតាម `id`។ ប្រើវាស័យនិយម OOP ដូចជា៖

* Class
* Object
* Member functions
* Encapsulation

---

### 🔸 គំរូ Code (C++)

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
    Student(int i, string n, float s) : id(i), name(n), score(s) {}

    int getId() const { return id; }
    string getName() const { return name; }
    float getScore() const { return score; }

    void setName(string n) { name = n; }
    void setScore(float s) { score = s; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Score: " << score << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, float score) {
        students.push_back(Student(id, name, score));
        cout << "✅ Student added.\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "📭 No students available.\n";
            return;
        }
        for (const auto& student : students)
            student.display();
    }

    void updateStudent(int id, string newName, float newScore) {
        for (auto& student : students) {
            if (student.getId() == id) {
                student.setName(newName);
                student.setScore(newScore);
                cout << "✏️ Student updated.\n";
                return;
            }
        }
        cout << "❌ Student not found.\n";
    }

    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "🔍 Student found:\n";
                student.display();
                return;
            }
        }
        cout << "❌ Student not found.\n";
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "🗑️ Student deleted.\n";
                return;
            }
        }
        cout << "❌ Student not found.\n";
    }
};

// -------- Main Program --------
int main() {
    StudentManager manager;
    int choice, id;
    string name;
    float score;

    do {
        cout << "\n📚 Student Management Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name, Score: ";
            cin >> id >> name >> score;
            manager.addStudent(id, name, score);
            break;
        case 2:
            manager.displayAll();
            break;
        case 3:
            cout << "Enter ID to update: ";
            cin >> id;
            cout << "Enter new Name and Score: ";
            cin >> name >> score;
            manager.updateStudent(id, name, score);
            break;
        case 4:
            cout << "Enter ID to search: ";
            cin >> id;
            manager.searchStudent(id);
            break;
        case 5:
            cout << "Enter ID to delete: ";
            cin >> id;
            manager.deleteStudent(id);
            break;
        case 0:
            cout << "👋 Exit Program.\n";
            break;
        default:
            cout << "❗ Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
```

---

### ✅ ការប្រើប្រាស់ក្នុងថ្នាក់:

* អ្នកអាចឱ្យនិស្សិតដាក់បញ្ចូលនិស្សិតជាច្រើននាក់ និងសាកល្បងស្វែងរក / កែប្រែ / លុបតាម ID។
* ជម្រើសអាចផ្លាស់ប្តូរតាមបំណង ដូចជា កំណត់ចំនួនអតិបរមានិស្សិត ឬអាចរកដោយឈ្មោះផងដែរ។

ចង់ឲ្យខ្ញុំបំលែងទៅជា worksheet, PDF ឬបន្ថែម UML diagram មែនទេ?
