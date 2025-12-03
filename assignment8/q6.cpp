#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;

    void heapifyUp(int index) {
        while(index > 1 && heap[index/2] < heap[index]) {
            swap(heap[index/2], heap[index]);
            index = index / 2;
        }
    }

    void heapifyDown(int index) {
        while(true) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if(left <= size && heap[left] > heap[largest])
                largest = left;
            if(right <= size && heap[right] > heap[largest])
                largest = right;

            if(largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int x) {
        heap[++size] = x;
        heapifyUp(size);
    }

    int getMax() {
        if(size == 0) return -1;
        return heap[1];
    }

    int extractMax() {
        if(size == 0) return -1;

        int maxVal = heap[1];
        heap[1] = heap[size--];

        heapifyDown(1);
        return maxVal;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for(int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);
    pq.insert(50);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Maximum = " << pq.getMax() << endl;

    cout << "Extracted Max = " << pq.extractMax() << endl;

    cout << "After extraction: ";
    pq.display();

    return 0;
}
