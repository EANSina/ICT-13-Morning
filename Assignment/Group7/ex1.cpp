#include <iostream>
using namespace std;
int findMinSalary(int salaries[], int size) {
    int minSalary = salaries[0]; // set the first value to the smallest value

    for (int i = 1; i < size; i++) {
        if (salaries[i] < minSalary) {
            minSalary = salaries[i]; // change the smallest value
        }
    }

    return minSalary;
}

int main() {
    int salaries[5] = {300, 140, 120, 250, 400};
    int size = sizeof(salaries) / sizeof(salaries[0]); // calculate the number of element in  array

    int minSalary = findMinSalary(salaries, size);

    cout << "the smallest price is: " << minSalary << endl;

    return 0;
}
