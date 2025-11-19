
#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for (int i=0;i<n1;i++) L[i]=a[l+i];
    for (int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int partitionArr(int a[], int low, int high) {
    int pivot = a[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partitionArr(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

void printArray(int a[], int n) {
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i=0; i<n; i++) cin >> a[i];

    cout << "Selection Sort: ";
    selectionSort(a, n);
    printArray(a, n);

    cout << "Insertion Sort: ";
    insertionSort(a, n);
    printArray(a, n);

    cout << "Bubble Sort: ";
    bubbleSort(a, n);
    printArray(a, n);

    cout << "Merge Sort: ";
    mergeSort(a, 0, n-1);
    printArray(a, n);

    cout << "Quick Sort: ";
    quickSort(a, 0, n-1);
    printArray(a, n);

    return 0;
}
