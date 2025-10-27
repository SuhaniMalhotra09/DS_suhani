Q1. //Implement the Binary search algorithm regarded as a fast search algorithm with run-time
//complexity of Ο(log n) in comparison to the Linear Search.
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 7;
    int arr[SIZE];

    cout << "Enter " << SIZE << " elements in sorted order:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "Enter array element to be found: ";
    int target;
    cin >> target;

    int start = 0;
    int end = SIZE - 1;
    int mid;
    bool flag = false;
    int index = -1;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == target) {
            flag = true;
            index = mid;
            break; 
        }
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    if (flag) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found" ;
    }

    return 0;
}
