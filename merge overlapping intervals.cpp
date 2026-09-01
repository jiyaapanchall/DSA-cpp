#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals:\n";

    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Step 1: Sort intervals by starting value
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    // Step 2: Merge overlapping intervals
    for (auto interval : intervals) {

        if (merged.empty() ||
            interval[0] > merged.back()[1]) {

            // No overlap
            merged.push_back(interval);
        }
        else {

            // Overlap
            merged.back()[1] =
                max(merged.back()[1], interval[1]);
        }
    }

    cout << "\nMerged intervals:\n";

    for (auto interval : merged) {
        cout << "[" << interval[0]
             << ", " << interval[1] << "] ";
    }

    return 0;
}