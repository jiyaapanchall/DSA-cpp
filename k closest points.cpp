#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, vector<int>>& a,
                    const pair<int, vector<int>>& b) {

        return a.first < b.first;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    priority_queue<
        pair<int, vector<int>>,
        vector<pair<int, vector<int>>>,
        Compare
    > maxHeap;

    for (auto& point : points) {

        int x = point[0];
        int y = point[1];

        int distance = x * x + y * y;

        maxHeap.push({distance, point});

        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    vector<vector<int>> result;

    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

int main() {

    vector<vector<int>> points = {
        {3, 3},
        {5, -1},
        {-2, 4}
    };

    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    cout << "K closest points: " << endl;

    for (auto point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}