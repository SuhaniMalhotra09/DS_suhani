Q8.//Write a program to count the total number of distinct elements in an array of length n.

  #include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinct = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

       
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            distinct++;
        }
    }

    cout << "Total distinct elements = " << distinct ;

    return 0;
}
