#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int Salary[5] = {300, 140, 120, 250, 400};

    int smallest = *min_element(Salary, Salary + 5);
    
    cout << "The smallest of salary: " << smallest << endl;
    return 0;
}
