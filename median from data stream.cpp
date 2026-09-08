#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

private:

    // Smaller half
    priority_queue<int> maxHeap;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:

    void addNum(int num) {

        // Step 1: Add to max heap
        maxHeap.push(num);

        // Step 2: Move largest from left half
        // to right half
        if (!minHeap.empty() &&
            maxHeap.top() > minHeap.top()) {

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Step 3: Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if (minHeap.size() > maxHeap.size()) {

            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Even number of elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {

    MedianFinder mf;

    mf.addNum(5);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(10);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;

    return 0;
}