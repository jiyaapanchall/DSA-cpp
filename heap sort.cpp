#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != i) {

        swap(arr[i], arr[largest]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {

    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {

        // Move current maximum to the end
        swap(arr[0], arr[i]);

        // Heapify the remaining heap
        heapify(arr, i, 0);
    }
}

int main() {

    vector<int> arr = {4, 10, 3, 5, 1};

    heapSort(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}