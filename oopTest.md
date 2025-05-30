បែបបទបញ្ចូលតម្លៃ **OOP ក្នុង C++** សម្រាប់សិស្សដំបូង ត្រូវសរសេរយ៉ាងលំអិត និងមានការពន្យល់ប្រកបដោយឧទាហរណ៍សាមញ្ញ។ ខាងក្រោមនេះជារបៀបនិងការពន្យល់ពីការបញ្ចូលតម្លៃទៅក្នុង **Class** នៅក្នុង OOP C++ ដើម្បីឲ្យសិស្សដំបូងយល់បានយ៉ាងងាយស្រួល៖

---

## 🔰១. តើ OOP (Object-Oriented Programming) ជាអ្វី?

OOP គឺជាវិធីសាស្រ្តសរសេរកម្មវិធីដែលផ្អែកលើ "វត្ថុ" (objects)។ វត្ថុមាន **ទិន្នន័យ** (data = attributes) និង **មុខងារ** (functions = methods) ដែលទៅពាក់ពន្ធនឹងវា។

➡️ កូដដែលផ្អែកលើ OOP ត្រូវការដំណើរការដូចជា៖

* ការបង្កើត **class**
* បង្កើត **object**
* បញ្ចូល **តម្លៃ** ទៅក្នុង object

---

## ✅២. បង្កើត Class និង Object (ឧទាហរណ៍សាមញ្ញ)

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void displayInfo() {
        cout << "ឈ្មោះ៖ " << name << endl;
        cout << "អាយុ៖ " << age << " ឆ្នាំ" << endl;
    }
};
```

📌 **ពន្យល់**៖

* `class Student`: បង្កើតថ្នាក់ឈ្មោះ Student។
* `string name; int age;`: គឺជា **attributes** (សម្បត្តិ/fields)។
* `displayInfo()`: ជា **method** ដើម្បីបង្ហាញព័ត៌មាននៃសិស្ស។

---

## ✏️៣. បញ្ចូលតម្លៃទៅក្នុង Object

មានពីរប្រភេទសំខាន់ៗ៖

### (1) បញ្ចូលតម្លៃដោយដៃ (manual assignment)

```cpp
int main() {
    Student s1;            // បង្កើត object ឈ្មោះ s1
    s1.name = "Sok Dara";  // បញ្ចូលឈ្មោះ
    s1.age = 18;           // បញ្ចូលអាយុ

    s1.displayInfo();      // បង្ហាញព័ត៌មាន
    return 0;
}
```

📌 **ពន្យល់**៖

* `s1.name = "Sok Dara";` → បញ្ចូលឈ្មោះទៅក្នុង object `s1`។
* `s1.age = 18;` → បញ្ចូលអាយុ។
* `s1.displayInfo();` → ហៅមុខងារ `displayInfo()` ដើម្បីបង្ហាញព័ត៌មាន។

---

### (2) បញ្ចូលតម្លៃតាម Constructor (ដំបូង advanced តែអាចបង្រៀនសិស្សកម្រិតខ្ពស់តិចៗបាន)

```cpp
class Student {
public:
    string name;
    int age;

    // Constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void displayInfo() {
        cout << "ឈ្មោះ៖ " << name << endl;
        cout << "អាយុ៖ " << age << " ឆ្នាំ" << endl;
    }
};

int main() {
    Student s1("Dara", 20);  // បញ្ចូលតម្លៃនៅពេលបង្កើត object
    s1.displayInfo();
    return 0;
}
```

📌 **ពន្យល់**៖

* `Student(string n, int a) {...}` គឺជា **constructor**។
* `Student s1("Dara", 20);` → បង្កើត object និងផ្ទុកតម្លៃទាំងអស់ក្នុងពេលតែមួយ។

---

## 🧠៤. ការបញ្ចូលតម្លៃដោយប្រើ `cin`

```cpp
int main() {
    Student s1;
    cout << "បញ្ចូលឈ្មោះសិស្ស: ";
    getline(cin, s1.name);      // ចូលទិន្នន័យឈ្មោះ
    cout << "បញ្ចូលអាយុសិស្ស: ";
    cin >> s1.age;              // ចូលអាយុ

    s1.displayInfo();
    return 0;
}
```

📌 **ពន្យល់**៖

* `getline(cin, s1.name);` → អានឈ្មោះដែលមានច្រើនពាក្យ។
* `cin >> s1.age;` → អានអាយុជាលេខ។

---

## 📌៥. ចំណាំសម្រាប់សិស្សដំបូង

* **Class** គឺដូចជា *ពុម្ពបែបបទ* (template)។
* **Object** គឺជា *គំរូពិតប្រាកដ* ដែលបានបង្កើតចេញពី class។
* តម្លៃអាចបញ្ចូលដោយ `object.attribute = value;`
* ឬតាម constructor នៅពេលបង្កើត object។

---

បើអ្នកចង់ឲ្យខ្ញុំធ្វើជាការបង្រៀនជា PowerPoint ឬ Word សម្រាប់បង្រៀនសិស្សដោយផ្ទាល់ សូមប្រាប់ខ្ញុំបន្ថែមបាន។
