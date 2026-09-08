#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int value;
    int arrayIndex;
    int elementIndex;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.value > b.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {

    priority_queue<Node, vector<Node>, Compare> minHeap;

    // Put the first element of every array into the heap
    for (int i = 0; i < arrays.size(); i++) {

        if (!arrays[i].empty()) {
            minHeap.push({
                arrays[i][0],
                i,
                0
            });
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {

        Node current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);

        int arrayIndex = current.arrayIndex;
        int elementIndex = current.elementIndex;

        // Move to the next element of the same array
        if (elementIndex + 1 < arrays[arrayIndex].size()) {

            minHeap.push({
                arrays[arrayIndex][elementIndex + 1],
                arrayIndex,
                elementIndex + 1
            });
        }
    }

    return result;
}

int main() {

    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> result = mergeKSortedArrays(arrays);

    cout << "Merged array: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}