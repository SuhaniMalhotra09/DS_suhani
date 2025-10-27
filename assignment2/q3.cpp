Q3.//Design the Logic to Find a Missing Number in a Sorted Array.

#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[7];
    int arrsum = 0;

    cout << "Enter 7 elements from 0 to 7 with one missing:\n";
    for(int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    int sum = (n * (n - 1)) / 2; 

    for(int i = 0; i < 7; i++) {
        arrsum += arr[i];
    }

    int missing = sum - arrsum;

    cout << "The element that is missing is: " << missing ;

    return 0;
}
