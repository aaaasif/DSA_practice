#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find a peak element
int findPeak(vector<int>& arr, int n) {
    stack<int> peaks;

    // Edge case: check if the first or last element is a peak
    if (n == 1 || arr[0] >= arr[1]) {
        peaks.push(0); // First element is a peak
    }
    if (arr[n - 1] >= arr[n - 2]) {
        peaks.push(n - 1); // Last element is a peak
    }

    // Traverse the array and check for peaks
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            peaks.push(i); // Current element is a peak
        }
    }

    // Return any one peak position
    if (!peaks.empty()) {
        return peaks.top(); // Return the top element of the stack
    }
    return -1; // If no peak is found (this should never happen with given constraints)
}

int main() {
    // Example test cases
    vector<vector<int>> testCases = {
        {4, 3, 9, 10, 14, 8, 7, 2, 5, 6},
        {1, 3, 20, 4, 1, 0},
        {10, 20, 15, 2, 23, 90, 67}
    };

    // Running the algorithm for each test case
    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].size();
        int peakIndex = findPeak(testCases[i], n);
        cout << "Peak at index " << peakIndex << " with value " << testCases[i][peakIndex] << endl;
    }

    return 0;
}
