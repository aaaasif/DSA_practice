#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find a peak element in the array
int findPeak(vector<int>& arr, int n) {
    stack<int> peaks; // Stack to store potential peaks

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

    // Return any one peak position from the stack
    if (!peaks.empty()) {
        return peaks.top(); // Return the top peak index from the stack
    }
    return -1; // If no peak is found (this should never happen in most valid cases)
}

int main() {
    int n; // Variable to store the length of the array

    // Input the length of the array
    cout << "Enter the length of the array (n): ";
    cin >> n;

    // Ensure the length is positive
    if (n <= 0) {
        cout << "Invalid length!" << endl;
        return 0; // Exit if the length is invalid
    }

    vector<int> arr(n); // Declare a vector to store the array elements

    // Input the array elements
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Reading input for the array
    }

    // Find the peak and display the result
    int peakIndex = findPeak(arr, n);
    if (peakIndex != -1) {
        cout << "Peak found at index " << peakIndex << " with value " << arr[peakIndex] << endl;
    } else {
        cout << "No peak found!" << endl;
    }

    return 0; // Terminate the program successfully
}
