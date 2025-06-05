#include <iostream>
using namespace std;

// Function to process salary array
void processSalary(int salary[], int size) {
    int total = 0, max = salary[0], min = salary[0];
    
    cout << "Salary Processing:" << endl;
    for(int i = 0; i < size; i++) {
        total += salary[i];
        if(salary[i] > max) max = salary[i];
        if(salary[i] < min) min = salary[i];
        cout << "Salary[" << i << "] = " << salary[i] << endl;
    }
    
    cout << "\nTotal Salary: " << total << endl;
    cout << "Average Salary: " << (double)total/size << endl;
    cout << "Maximum Salary: " << max << endl;
    cout << "Minimum Salary: " << min << endl;
}

int main() {
    int Salary[5] = {100, 150, 100, 50, 40};
    processSalary(Salary, 5);
    return 0;
}

