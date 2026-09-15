#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partitionArray(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {

            i++;

            swap(arr[i], arr[j]);
        }
    }

    // Put pivot in its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low >= high)
        return;

    int pivotIndex = partitionArray(arr, low, high);

    // Sort left part
    quickSort(arr, low, pivotIndex - 1);

    // Sort right part
    quickSort(arr, pivotIndex + 1, high);
}

int main() {

    vector<int> arr = {5, 2, 8, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}