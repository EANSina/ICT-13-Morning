#include <iostream>
using namespace std;

void processSalaryArray(int salary[], int size) {
    // Example operations on the salary array
    cout << "Processing salary array:\n";
    
    // 1. Print all elements
    cout << "All salaries: ";
    for(int i = 0; i < size; i++) {
        cout << salary[i] << " ";
    }
    cout << endl;
    
    // 2. Find maximum salary
    int max = salary[0];
    for(int i = 1; i < size; i++) {
        if(salary[i] < max) {
            max = salary[i];
        }
    }
    cout << "Minimum salary: " << max << endl;
    
    // 3. Calculate average
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += salary[i];
    }
    double average = static_cast<double>(sum) / size;
    cout << "Average salary: " << average << endl;
}

int main() {
    int salary[5] = {300, 140, 120, 250, 400};
    processSalaryArray(salary, 5);
    return 0;
}
