**ចំនួនបុគ្គលិកសរុប** និង **ប្រាក់ខែសរុប**៖

---

### ✅ កូដ C++ ពេញលេញ (Rewritten with Fixes and Comments)

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    int id;
    string name, gender, position;
    double salary;

public:
    Employee() {
        id = 0;
        name = "Unknown";
        gender = "Unknown";
        position = "Unknown";
        salary = 0;
    }

    // Getter methods
    int getId() { return id; }
    string getName() { return name; }
    string getGender() { return gender; }
    string getPosition() { return position; }
    double getSalary() { return salary; }

    // Setter methods
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setGender(string gender) { this->gender = gender; }
    void setPosition(string position) { this->position = position; }
    void setSalary(double salary) { this->salary = salary; }

    // Input employee
    void input() {
        cout << "Input Employee ID       : "; cin >> id;
        cin.ignore(); // clear buffer
        cout << "Input Employee Name     : "; getline(cin, name);
        cout << "Input Employee Gender   : "; cin >> gender;
        cout << "Input Employee Position : "; cin >> position;
        cout << "Input Employee Salary   : "; cin >> salary;
    }

    // Output employee
    void output() {
        cout << setw(10) << id
             << setw(15) << name
             << setw(10) << gender
             << setw(15) << position
             << setw(10) << fixed << setprecision(2) << salary << endl;
    }

    // Print table header
    void printHeader() {
        cout << setw(10) << "ID"
             << setw(15) << "Name"
             << setw(10) << "Gender"
             << setw(15) << "Position"
             << setw(10) << "Salary" << endl;
    }

    // List all employees
    void getList(Employee obj[], int n) {
        printHeader();
        for (int i = 0; i < n; i++) {
            obj[i].output();
        }
    }

    // Search by ID
    void searchById(Employee obj[], int n) {
        int idSearch, isFound = 0;
        cout << "Input Employee ID to search: "; cin >> idSearch;
        for (int i = 0; i < n; i++) {
            if (idSearch == obj[i].getId()) {
                printHeader();
                obj[i].output();
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            cout << "Message >>> ID " << idSearch << " not found." << endl;
    }

    // Search by Name
    void searchByName(Employee obj[], int n) {
        string textSearch;
        int isFound = 0;
        cout << "Input Employee Name to search: "; cin >> textSearch;
        for (int i = 0; i < n; i++) {
            if (textSearch == obj[i].getName()) {
                printHeader();
                obj[i].output();
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            cout << "Message >>> Name " << textSearch << " not found." << endl;
    }

    // Search by Position
    void searchByPosition(Employee obj[], int n) {
        string textSearch;
        int isFound = 0;
        cout << "Input Employee Position to search: "; cin >> textSearch;
        for (int i = 0; i < n; i++) {
            if (textSearch == obj[i].getPosition()) {
                printHeader();
                obj[i].output();
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            cout << "Message >>> Position " << textSearch << " not found." << endl;
    }

    // Sort by Name ASC
    void sortNameASC(Employee obj[], int n) {
        Employee temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (obj[i].getName() > obj[j].getName()) {
                    temp = obj[i];
                    obj[i] = obj[j];
                    obj[j] = temp;
                }
            }
        }
        cout << "========== Sort Name ASC ==========" << endl;
        getList(obj, n);
    }

    // Sort by Name DESC
    void sortNameDESC(Employee obj[], int n) {
        Employee temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (obj[i].getName() < obj[j].getName()) {
                    temp = obj[i];
                    obj[i] = obj[j];
                    obj[j] = temp;
                }
            }
        }
        cout << "========== Sort Name DESC ==========" << endl;
        getList(obj, n);
    }

    // Sort by Salary ASC
    void sortSalaryASC(Employee obj[], int n) {
        Employee temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (obj[i].getSalary() > obj[j].getSalary()) {
                    temp = obj[i];
                    obj[i] = obj[j];
                    obj[j] = temp;
                }
            }
        }
        cout << "========== Sort Salary ASC ==========" << endl;
        getList(obj, n);
    }

    // Sort by Salary DESC
    void sortSalaryDESC(Employee obj[], int n) {
        Employee temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (obj[i].getSalary() < obj[j].getSalary()) {
                    temp = obj[i];
                    obj[i] = obj[j];
                    obj[j] = temp;
                }
            }
        }
        cout << "========== Sort Salary DESC ==========" << endl;
        getList(obj, n);
    }

    // Delete by ID
    void deleteById(Employee obj[], int &n) {
        int idSearch, isFound = 0;
        cout << "Input Employee ID to delete: "; cin >> idSearch;
        for (int i = 0; i < n; i++) {
            if (idSearch == obj[i].getId()) {
                for (int j = i; j < n - 1; j++) {
                    obj[j] = obj[j + 1];
                }
                n--;
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            cout << "Message >>> ID " << idSearch << " not found." << endl;
        else
            getList(obj, n);
    }

    // Update by ID
    void updateById(Employee obj[], int n) {
        int idSearch, isFound = 0, optionUpdate;
        cout << "Input Employee ID to update: "; cin >> idSearch;
        for (int i = 0; i < n; i++) {
            if (idSearch == obj[i].getId()) {
                obj->printHeader();
                obj[i].output();
                cout << "=== What do you want to update (1-5)? ===" << endl;
                cout << "1. Name\n2. Gender\n3. Position\n4. Salary\n5. All\nChoice: ";
                cin >> optionUpdate;
                cin.ignore();
                switch (optionUpdate) {
                    case 1: cout << "New Name: "; getline(cin, obj[i].name); break;
                    case 2: cout << "New Gender: "; cin >> obj[i].gender; break;
                    case 3: cout << "New Position: "; cin >> obj[i].position; break;
                    case 4: cout << "New Salary: "; cin >> obj[i].salary; break;
                    case 5:
                        cout << "New Name: "; getline(cin, obj[i].name);
                        cout << "New Gender: "; cin >> obj[i].gender;
                        cout << "New Position: "; cin >> obj[i].position;
                        cout << "New Salary: "; cin >> obj[i].salary;
                        break;
                }
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            cout << "Message >>> ID " << idSearch << " not found." << endl;
    }

    // Get total salary
    double getTotalSalary(Employee obj[], int n) {
        double total = 0;
        for (int i = 0; i < n; i++)
            total += obj[i].getSalary();
        return total;
    }

    // Get total employees
    int getTotalEmployee(int n) {
        cout << "========== Total Employees ==========" << endl;
        cout << "Total Employee: " << n << endl;
        cout << "=====================================" << endl;
        return n;
    }
};

// ================= MAIN PROGRAM ===================

int main() {
    Employee objE[100];
    int n = 0, option, optionSub;

    do {
        cout << "\n======= Employee Management Menu =======" << endl;
        cout << "1. Input Employee\n2. List All\n3. Search\n4. Sort\n5. Delete\n6. Update\n7. Total Salary\n8. Total Employee\n9. Exit" << endl;
        cout << "Choose option (1-9): ";
        cin >> option;

        switch (option) {
            case 1:
                objE[n].input();
                n++;
                break;
            case 2:
                objE->getList(objE, n);
                break;
            case 3:
                do {
                    cout << "=== Search Menu ===\n1. By ID\n2. By Name\n3. By Position\n4. Back\nChoose: ";
                    cin >> optionSub;
                    switch (optionSub) {
                        case 1: objE->searchById(objE, n); break;
                        case 2: objE->searchByName(objE, n); break;
                        case 3: objE->searchByPosition(objE, n); break;
                    }
                } while (optionSub != 4);
                break;
            case 4:
                do {
                    cout << "=== Sort Menu ===\n1. Name ASC\n2. Name DESC\n3. Salary ASC\n4. Salary DESC\n5. Back\nChoose: ";
                    cin >> optionSub;
                    switch (optionSub) {
                        case 1: objE->sortNameASC(objE, n); break;
                        case 2: objE->sortNameDESC(objE, n); break;
                        case 3: objE->sortSalaryASC(objE, n); break;
                        case 4: objE->sortSalaryDESC(objE, n); break;
                    }
                } while (optionSub != 5);
                break;
            case 5:
                objE->deleteById(objE, n);
                break;
            case 6:
                objE->updateById(objE, n);
                break;
            case 7:
                cout << "========== Total Salary ==========\n";
                cout << "Total Salary: $" << objE->getTotalSalary(objE, n) << endl;
                cout << "==================================" << endl;
                break;
            case 8:
                objE->getTotalEmployee(n);
                break;
            case 9:
                exit(0);
        }
    } while (true);

    return 0;
}
```

---

### 📌 លក្ខណៈពិសេស

* 🔍 ស្វែងរកតាម ID / Name / Position
* 🧮 របាយការណ៍ប្រាក់ខែសរុប និងចំនួនបុគ្គលិក
* 🧾 ប្រើ array ដើម្បីរក្សាទុកឯកសារបុគ្គលិក

<!-- បើអ្នកចង់បន្ថែម Menu របាយការណ៍ ឬប្រើ `vector` ជំនួស `array` សូមប្រាប់ខ្ញុំបន្ថែមបាន។ -->
### SearchByID
```cpp
//SearchByID
		void searchById(Employee obj[], int n){
			int idSearch, isFound;
			cout<<"Input Employee id to search : ";cin >>idSearch;
			isFound=0;
			for(int i=0; i<n; i++){
				if(idSearch == obj[i].getId()){
					printHeader();
					obj[i].output();
					isFound=1;
					break;
				}
			}
			
			if(isFound==0){
				cout<<"Message >>>(ID"<<idSearch<<"not fourn "<<endl;
			}
		}
```

| **បន្ទាត់**                                                        | **អត្ថន័យ**                                                                                                    |
| ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------- |
| `void searchById(Employee obj[], int n)`                           | Function មានឈ្មោះ `searchById` មិនបញ្ជូនតម្លៃត្រឡប់។ វទទួលអារេនិយោជិក `obj[]` និងចំនួន `n` (ចំនួននិយោជិកសរុប)។ |
| `int idSearch, isFound;`                                           | ប្រកាសអថេរ `idSearch` (ID ដែលអ្នកចង់ស្វែងរក) និង `isFound` (សម្គាល់ថាទាន់រកឃើញ ID ឬទេ)។                        |
| `cout << "Input Employee id to search : "; cin >> idSearch;`       | សួរអ្នកប្រើឲ្យបញ្ចូលលេខ ID ដើម្បីស្វែងរក។                                                                      |
| `isFound = 0;`                                                     | កំណត់ដើមថា ID មិនទាន់ត្រូវបានរកឃើញ។                                                                            |
| `for (int i = 0; i < n; i++)`                                      | វង់តាមនិយោជិកទាំងអស់ក្នុងអារេ `obj[]`                                                                          |
| `if (idSearch == obj[i].getId())`                                  | ប្រៀបធៀប `idSearch` ជាមួយ ID របស់និយោជិកលើតំណេីរទី `i`                                                         |
| `printHeader(); obj[i].output();`                                  | បើ ID ត្រូវគ្នា ត្រូវបោះពុម្ពឈ្មោះកូឡុំ ហើយបង្ហាញព័ត៌មាននិយោជិកនោះ                                             |
| `isFound = 1; break;`                                              | បើរកឃើញ ID ដូចគ្នា កំណត់ថា “រកឃើញ” ហើយបញ្ចប់វង់                                                                |
| `if (isFound == 0)`                                                | បើមិនរកឃើញសោះ (ID មិនមានក្នុងបញ្ជី)                                                                            |
| `cout << "Message >>> (ID " << idSearch << " not found)" << endl;` | បង្ហាញសារ "not found"                                                                                          |

ខាងក្រោមនេះជាកូដ `searchByName` ដែលបាន **កែសម្រួលឡើងវិញ** ដើម្បីជៀសវាងបញ្ហា syntax error និងធ្វើឲ្យលទ្ធផលបង្ហាញបានត្រឹមត្រូវជាមួយសារមានន័យច្បាស់៖

---

### ✅ កូដ​​ (searchByName`):

```cpp
// Search By Name
void searchByName(Employee obj[], int n) {
    string textSearch;
    bool isFound = false;

    cout << "Input Employee name to search: ";
    cin.ignore(); // clear newline from buffer
    getline(cin, textSearch); // support names with spaces

    for (int i = 0; i < n; i++) {
        if (textSearch == obj[i].getName()) {
            printHeader();
            obj[i].output();
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        cout << "Message >>> Name \"" << textSearch << "\" not found." << endl;
    }
}
```

---

### 🛠 ការកែសម្រួលដែលបានធ្វើ:

| ធាតុ                                                             | ពន្យល់                                               |
| ---------------------------------------------------------------- | ---------------------------------------------------- |
| `cin.ignore()`                                                   | ជួយដក character `\n` មុនពេល `getline()`              |
| `getline(cin, textSearch)`                                       | អនុញ្ញាតឲ្យបញ្ចូលឈ្មោះមាន space (e.g. "Sok Dara")    |
| `bool isFound = false;`                                          | ប្រើ `bool` ជំនួស `int` ដើម្បីពិចារណាផ្នែកត្រឹមត្រូវ |
| `cout << "Message >>> Name \"" << textSearch << "\" not found."` | បង្ហាញសារបង្ហាញ error មានសោភាពកាន់តែល្អ              |

---
ខាងក្រោមនេះជាកូដ `searchByPosition` ដែលបាន **កែសម្រួលឡើងវិញ** ដើម្បីឲ្យមានតម្លាភាព និងប្រើបានប្រក្រតី៖

---

### ✅ កូដដែលបានកែសម្រួល (Fixed `searchByPosition` function):

```cpp
// Search By Position
void searchByPosition(Employee obj[], int n) {
    string textSearch;
    bool isFound = false;

    cout << "Input Employee position to search: ";
    cin.ignore(); // clear the newline character from buffer
    getline(cin, textSearch); // allow multi-word positions

    for (int i = 0; i < n; i++) {
        if (textSearch == obj[i].getPosition()) {
            if (!isFound) {
                printHeader();
                isFound = true;
            }
            obj[i].output();
        }
    }

    if (!isFound) {
        cout << "Message >>> Position \"" << textSearch << "\" not found." << endl;
    }
}
```

---

### 🛠 ការកែសម្រួលដ៏សំខាន់:

| ធាតុ                                                     | ពន្យល់                                               |
| -------------------------------------------------------- | ---------------------------------------------------- |
| `cin.ignore()` និង `getline()`                           | អាចបញ្ចូល `position` មាន space (ឧ. "Senior Manager") |
| `bool isFound = false;`                                  | ជំនួស `int isFound` ដើម្បីប្រើ `true/false` ងាយស្រួល |
| `if (!isFound) printHeader();`                           | បង្ហាញ `header` តែពេលបានរកឃើញឯណាមួយ                  |
| `cout << "Position \"" << textSearch << "\" not found."` | បង្ហាញសារ error ច្បាស់ឃើញ និងអានងាយ                  |

---

ខាងក្រោមនេះជាកូដ `sortNameASC` ដែលបាន **អានបកស្រាយ និងកែសម្រួលបន្ថែមអោយប្រសើរឡើង**៖

---

### ✅ កូដដែលបានកែសម្រួល (Sort Name Ascending):

```cpp
// Sort Name in Ascending Order (A → Z)
void sortNameASC(Employee obj[], int n) {
    Employee objTmp;
    for (int i = 0; i < n - 1; i++) {         // Bubble Sort logic
        for (int j = i + 1; j < n; j++) {
            if (obj[i].getName() > obj[j].getName()) {
                objTmp = obj[i];
                obj[i] = obj[j];
                obj[j] = objTmp;
            }
        }
    }

    cout << "========== Sort Name ASCENDING (A → Z) ==========" << endl;
    printHeader();
    for (int i = 0; i < n; i++) {
        obj[i].output();
    }
}
```

---

### 📝 ពន្យល់កូដជាភាសាខ្មែរ៖

| ផ្នែក                                                | ពន្យល់                                              |
| ---------------------------------------------------- | --------------------------------------------------- |
| `for (int i = 0; i < n - 1; i++)`                    | ជាជំហានដើរតាមលំដាប់រៀងរបស់អតិថិជន                   |
| `if (obj[i].getName() > obj[j].getName())`           | ប្រៀបធៀបឈ្មោះតាមលំដាប់អក្សរ (A-Z)                   |
| `objTmp = obj[i]; obj[i] = obj[j]; obj[j] = objTmp;` | ប្តូរទីតាំងរវាងអតិថិជន 2 នាក់ ប្រសិនបើមិនត្រឹមត្រូវ |
| `printHeader();` និង `output();`                     | បង្ហាញជារៀងរហូតបន្ទាប់ពីបានតម្រៀបរួច                |

---

### 📌 សេចក្តីសន្និដ្ឋាន

កូដនេះប្រើវិធីសាស្ត្រ **Bubble Sort** ដើម្បីតម្រៀបឈ្មោះ `Employee` តាមលំដាប់ **A → Z**។ ប្រសិនបើអ្នកចង់កែជារៀងបញ្ច្រាស (Z → A), សូមប្រាប់ខ្ញុំដើម្បីសរសេរកូដ `sortNameDESC()` ផងដែរ។

តើអ្នកចង់អោយខ្ញុំបង្កើតកូដ `sortNameDESC` ឬ `sortBySalaryASC/DESC` ដែរទេ?

ចាស! ខាងក្រោមនេះជាការពន្យល់លំអិត **កូដ C++ `sortNameASC()`** ដែលប្រើសម្រាប់តម្រៀបឈ្មោះនិយោជិកតាមលំដាប់ **A → Z (Ascending Order)** ដោយប្រើ **Bubble Sort**។

---

## 🔰 គោលបំណង (Purpose)

```cpp
void sortNameASC(Employee obj[], int n)
```

អនុគមន៍នេះមានបំណង **តម្រៀបនិយោជិក (Employee)** ដោយផ្អែកលើ **ឈ្មោះ (Name)** តាមលំដាប់ **A → Z** (គឺតម្រៀបឈ្មោះតូចទៅធំតាមអក្សរ) ហើយបង្ហាញតារាងលទ្ធផលក្រោយពេលបានតម្រៀបរួច។

---

## 📘 កូដដើម៖

```cpp
void sortNameASC(Employee obj[], int n){
    Employee objTmp;
    for (int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(obj[i].getName() > obj[j].getName()){
                objTmp = obj[i];
                obj[i] = obj[j];
                obj[j] = objTmp;
            }
        }
    }	
    cout << "========== Sort name ASC ==========" << endl;
    getList(obj, n);
}
```

---

## 🧠 ពន្យល់លំអិត៖

### 🔹 `Employee obj[], int n`

* `obj[]` គឺជាអារេនៃ Object `Employee`។
* `n` គឺចំនួននិយោជិកសរុបនៅក្នុង `obj[]`។

---

### 🔹 `Employee objTmp;`

* បង្កើត Object មួយជាបណ្តោះអាសន្នដើម្បីធ្វើការ **ប្តូរទិន្នន័យ (swap)**។

---

### 🔹 Loop ទីមួយ៖ `for (int i = 0; i < n; i++)`

* ដើរតាមនិយោជិកពីទីតាំង 0 → n-1 (លើកលែងចុងក្រោយ)។

---

### 🔹 Loop ទីពីរ៖ `for (int j = i + 1; j < n; j++)`

* ប្រៀបធៀបនិយោជិកទី `i` ជាមួយ `j = i + 1` → n-1។

---

### 🔹 ការប្រៀបធៀបឈ្មោះ៖

```cpp
if(obj[i].getName() > obj[j].getName())
```

* ប្រើ `>` ដើម្បីប្រៀបឈ្មោះតាមលំដាប់អក្សរ។
* ឧ. "John" > "Alex" → ត្រូវប្ដូរទីតាំង (ត្រឡប់ទៅលំដាប់ A-Z)។

---

### 🔹 ប្តូរទីតាំង (Swap):

```cpp
objTmp = obj[i];
obj[i] = obj[j];
obj[j] = objTmp;
```

* ប្រើ `objTmp` ជា Temporary Object ដើម្បីសម្រួលការប្តូរ **Object** ទាំងមូល។

---

### 🔹 បង្ហាញលទ្ធផលក្រោយតម្រៀប

```cpp
cout << "========== Sort name ASC ==========" << endl;
getList(obj, n);
```

* បង្ហាញចំណងជើង និងប្រើអនុគមន៍ `getList()` ដើម្បីបង្ហាញតារាងនិយោជិកក្រោយពីបានតម្រៀប។

---

## 📌 ឧទាហរណ៍

**មុនតម្រៀប**៖

* Linda
* David
* Anna

**ក្រោយតម្រៀប ASC (A-Z)**៖

* Anna
* David
* Linda

---

## 📎 ចំណាំសម្រាប់សិស្ស

* ការប្រៀបធៀប `string` ដោយប្រើ `>` ឬ `<` នៅក្នុង C++ គឺអាចធ្វើបានដោយផ្ទាល់ ព្រោះ `string` គឺជា Class ដែលមាន `operator >` និង `operator <` បាន Overload ជារួច។
* អ្នកអាចប្រើ `obj[i].getName()` ដើម្បីយកឈ្មោះនិយោជិកនីមួយៗមកប្រៀបធៀប។

---

កូដនេះជាមុខងារ **deleteById** ដែលប្រើសម្រាប់លុបបុគ្គលិកតាមរយៈ **ID** នៅក្នុងបញ្ជីបុគ្គលិក។ ខាងក្រោមនេះជាការពន្យល់លម្អិតតាមជំហាន៖

---

## ✅ **មុខងារ**:

```cpp
void deleteById(Employee obj[], int &n)
```

* `obj[]`: ជាអារេរបស់ `Employee` (បញ្ជីបុគ្គលិក)។
* `n`: ជាចំនួនបុគ្គលិកសរុប។ ប្រើ `&n` ដើម្បីអាចបន្ថយចំនួនបាន (pass by reference)។

---

## 🔍 **ការពន្យល់កូដតាមជំហាន**:

### 1️⃣ កំណត់តម្លៃដើម

```cpp
int idSearch, isFound;
cout <<"Input employee id to delete : "; 
cin >> idSearch;
isFound = 0;
```

* ស្នើឲ្យអ្នកប្រើបញ្ចូល **ID** របស់បុគ្គលិកដែលត្រូវលុប។
* `isFound = 0;` គ្រាន់តែសម្គាល់ថាតើរកឃើញ ID នោះទេ។

---

### 2️⃣ រក ID ត្រូវ

```cpp
for (int i = 0; i < n; i++) {
    if (idSearch == obj[i].getId()) {
        ...
    }
}
```

* វាឆ្ពោះតាមបញ្ជីបុគ្គលិក ដើម្បីស្វែងរក `ID` ដែលត្រូវនឹង `idSearch` ។

---

### 3️⃣ ប្រសិនបើរកឃើញ => លុប

```cpp
for(int j = i; j < n; j++) {
    obj[j] = obj[j + 1];
}
n--;
isFound = 1;
break;
```

* វាដាក់អត្តសញ្ញាណបន្ទាប់ (obj\[j+1]) ជំនួស obj\[j] → នេះគឺជាការរំកិលចុះមួយជំហាន។
* បន្ទាប់ពីលុប ត្រូវបន្ថយ `n--` (ចំនួនបុគ្គលិកកាត់បន្ថយ)។
* `break;` ចេញពី loop ដើម្បីចៀសវាងការស្វែងរកបន្ថែម។

---

### 4️⃣ ប្រសិនបើរក **មិនឃើញ**

```cpp
if (isFound == 0) {
    cout << "Message id << " << idSearch << " >> not found" << endl;
}
```

* ប្រសិនបើមិនមាន ID ត្រូវនោះទេ បង្ហាញសារ។

---

### 5️⃣ បង្ហាញបញ្ជីក្រោយលុប

```cpp
getList(obj, n);
```

* បង្ហាញបញ្ជីបុគ្គលិកទាំងអស់ក្រោយការលុបបានធ្វើរួច។

---

## 🧠 ឧទាហរណ៍

**មុនលុប**:

```text
Index:   0     1     2
ID:     101   102   103
```

បញ្ចូល `idSearch = 102`
→ `i = 1`

ការរំកិល៖

```cpp
obj[1] = obj[2];   // ID 102 -> 103
```

**ក្រោយលុប**:

```text
Index:   0     1
ID:     101   103
n = 2
```

---

## 📌 ចំណាំសម្រាប់សិស្ស

* ត្រូវប្រើ `int &n` ដើម្បីអាចផ្លាស់ប្ដូរចំនួនគិតតាមករណីលុប។
* ប្រសិនបើមិនប្រើ `break;` → វាអាចលុបច្រើនជំពូក (ប្រសិនបើមាន ID ដូចគ្នាច្រើន)។
* ការរំកិល `obj[j] = obj[j+1]` គឺជាវិធីដ៏ល្អក្នុងការដោះចេញអង្គធាតុមួយពីអារេរ។

---

ខាងក្រោមនេះជាការពន្យល់លម្អិតនៃមុខងារ `updateById()` ដែលអនុញ្ញាតឲ្យអ្នកអាប់ដេតព័ត៌មានបុគ្គលិកតាមរយៈ **ID**។

---

### ✅ **មុខងារ**:

```cpp
void updateById(Employee obj[], int n)
```

* `obj[]`: ជាអារេរបស់វត្ថុ `Employee` (បញ្ជីបុគ្គលិក)
* `n`: ចំនួនបុគ្គលិក
* មុខងារនេះអនុញ្ញាតឲ្យអ្នកជ្រើសរើសធ្វើការអាប់ដេត **1** ក្នុងចំណោម **5** ផ្នែក (ឬទាំងអស់) នៅលើបុគ្គលិកដែលមាន `ID` ត្រូវនឹងការបញ្ចូលរបស់អ្នកប្រើ។

---

## 🔍 ការពន្យល់ជំហានៗ

### 1. បញ្ចូល ID ដែលត្រូវអាប់ដេត

```cpp
int idSearch, isFound, optionUpdate;
cout << "Input employee id to update : "; 
cin >> idSearch;
isFound = 0;
```

---

### 2. ស្វែងរក ID ដែលត្រូវនឹង

```cpp
for (int i = 0; i < n; i++) {
    if (idSearch == obj[i].getId()) {
```

* ប្រើ loop ដើម្បីស្វែងរកបុគ្គលិកដែលមាន ID ត្រូវនឹង `idSearch`

---

### 3. បង្ហាញព័ត៌មានបច្ចុប្បន្ន និងជ្រើសរើសអាប់ដេត

```cpp
obj->printHeader();
obj[i].output();
```

* បង្ហាញ header និងព័ត៌មានបុគ្គលិកដែលត្រូវបានស្វែងរក

---

### 4. ជម្រើសអាប់ដេត

```cpp
cout << "1. Update Name" << endl;
cout << "2. Update Gender" << endl;
cout << "3. Update Position" << endl;
cout << "4. Update Salary" << endl;
cout << "5. Update all" << endl;
```

→ អ្នកប្រើអាចជ្រើសរើស update តែផ្នែកណាមួយ ឬ update ទាំងអស់។

---

### 5. Update តាមជម្រើស

```cpp
switch(optionUpdate){
    case 1:
        cout<< "Input new name :"; cin >> obj[i].name;
        break;
    ...
    case 5:
        cout<< "Input new name :"; cin >> obj[i].name;
        cout<< "Input new gender :"; cin >> obj[i].gender;
        ...
}
```

**សំខាន់**: គ្រាន់តែប្រើ `obj[i].name` ទាំងផ្ទាល់ (សន្មតថា `name` ជា public variable)។ ប្រសិនបើ `name`, `gender`, `position`, `salary` ជា **private**, ត្រូវប្រើ setter function ដូចជា:

```cpp
obj[i].setName("new name");
```

---

### 6. បង្ហាញសារប្រសិនបើរកមិនឃើញ

```cpp
if (isFound == 0) {
    cout << "Message id << " << idSearch << " >> not found in list !" << endl;
}
```

---

## 🔧 កំណែប្រែកូដល្អប្រសើរជាងមុន

ប្រសិនបើ `name`, `gender`, `position`, `salary` ជា **private** នៅក្នុង class `Employee`, ត្រូវប្រើ Setter Functions:

```cpp
case 1: {
    string newName;
    cout << "Input new name : "; cin >> newName;
    obj[i].setName(newName);
    break;
}
```

---

## 📌 បញ្ហាដែលត្រូវកែប្រែក្នុងកូដដើម

| 🧱 កូដដើម                       | 🛠️ ត្រូវកែជា                              |
| ------------------------------- | ------------------------------------------ |
| `obj->printHeader();`           | `printHeader();`                           |
| `obj[i].name = ...`             | `obj[i].setName(...);` *(ប្រសិន private)*  |
| សរសេរ string មួយៗចំពោះ `cin >>` | ប្រើ `getline(cin, ...)` ប្រសិនបើមាន space |

---

## 🧠 ឧទាហរណ៍ប្រើប្រាស់

```text
Input employee id to update : 101
[Header + info employee 101]
=== What you want to update (1-5)? ===
1. Update Name
2. Update Gender
3. Update Position
4. Update Salary
5. Update all
Enter Option: 3
Input new position: Manager
```

---
