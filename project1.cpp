#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the number of peak elements in the array
int countPeaks(vector<int>& arr, int n) {
    int peakCount = 0; // Variable to count the number of peaks

    // Edge case: check if the first or last element is a peak
    if (n == 1 || arr[0] >= arr[1]) {
        peakCount++; // First element is a peak
    }
    if (n > 1 && arr[n - 1] >= arr[n - 2]) {
        peakCount++; // Last element is a peak
    }

    // Traverse the array and check for peaks
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            peakCount++; // Current element is a peak
        }
    }

    return peakCount; // Return the total number of peaks
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

    // Find the number of peaks and display the result
    int numberOfPeaks = countPeaks(arr, n);
    cout << "Number of peaks: " << numberOfPeaks << endl;

    return 0; // Terminate the program successfully
}
