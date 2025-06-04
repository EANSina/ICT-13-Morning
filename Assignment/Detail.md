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

បើអ្នកចង់បន្ថែម Menu របាយការណ៍ ឬប្រើ `vector` ជំនួស `array` សូមប្រាប់ខ្ញុំបន្ថែមបាន។




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
s