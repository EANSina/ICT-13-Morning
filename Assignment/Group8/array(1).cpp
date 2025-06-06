


#include <iostream>
using namespace std;
int findSmallest(int arr[], int size) {
    if (size <= 0) {
        return INT_MAX; // Return a large value if the array is empty
    }

    int smallest = arr[0]; // Assume the first element is the smallest initially

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i]; // Update smallest if a smaller value is found
        }
    }
    return smallest;
}

int main() {
    int salary[5] = {300, 140, 120, 250, 400};
    int size = sizeof(salary) / sizeof(salary[0]);
    int smallestValue = findSmallest(salary, size);
    std::cout << "The smallest value in the array is: " << smallestValue << std::endl;
    return 0;
}
