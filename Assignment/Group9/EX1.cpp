#include <iostream>
using namespace std;

// Function to find minimum value in array
int findMin(int arr[], int size) {
    int min = arr[0]; // assume first element is min
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; // update min if smaller element found
        }
    }
    return min;
}

int main() {
    int Salary[5] = {100, 140, 120, 250, 400};

    int minValue = findMin(Salary, 5);

    cout << "The minimum salary is: " << minValue << endl;

    return 0;
}
