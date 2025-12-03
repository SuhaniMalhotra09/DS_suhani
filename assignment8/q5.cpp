#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool maxHeap) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (maxHeap) {
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
    } else {
        if (left < n && arr[left] < arr[largest]) largest = left;
        if (right < n && arr[right] < arr[largest]) largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, maxHeap);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    bool maxHeap = increasing;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, maxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, maxHeap);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 5, 15, 22, 10};
    int n = 5;

    heapSort(arr, n, true);
    print(arr, n);

    int arr2[] = {20, 5, 15, 22, 10};
    heapSort(arr2, n, false);
    print(arr2, n);

    return 0;
}
