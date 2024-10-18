#include <iostream>
#include <vector>
using namespace std;

// Function to find and display the peaks in the array and count their occurrences
int findAndDisplayPeaks(vector<int>& arr, int n) {
    int peakCount = 0; // Variable to count the number of peaks

    cout << "The peak number(s) is/are: ";

    // Check the first element
    if (n == 1 || arr[0] >= arr[1]) {
        cout << arr[0]; // First element is a peak
        peakCount++; // Count the peak
    }

    // Traverse the array and check for peaks
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            if (peakCount > 0) {
                cout << " -> "; // Arrow between peak numbers
            }
            cout << arr[i]; // Current element is a peak
            peakCount++; // Increment the number of peaks
        }
    }

    // Check the last element
    if (n > 1 && arr[n - 1] >= arr[n - 2]) {
        if (peakCount > 0) {
            cout << " -> "; // Arrow between peak numbers
        }
        cout << arr[n - 1]; // Last element is a peak
        peakCount++; // Count the peak
    }

    cout << endl;
    return peakCount; // Return the total number of peaks
}

int main() {
    int n; // Variable to store the length of the array

    // Input the length of the array
    cout << "What is the size of your list? " << endl;
    cin >> n;

    // Ensure the length is positive
    if (n <= 0) {
        cout << "Invalid length!" << endl;
        return 0; // Exit if the length is invalid
    }

    vector<int> arr(n); // Declare a vector to store the array elements

    // Input the array elements
    cout << "Enter values of the list. You have to enter " << n << " values." << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Reading input for the array
    }

    // Display all the list values
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " -> "; // Add arrows between elements
        cout << arr[i]; // Print the element
    }
    cout << endl;

    // Find and display the peaks, and count how many peaks are found
    int numberOfPeaks = findAndDisplayPeaks(arr, n);
    
    // Output the number of peaks found
    if (numberOfPeaks == 1) {
        cout << "There is " << numberOfPeaks << " peak in this list." << endl;
    } else {
        cout << "There are " << numberOfPeaks << " peaks in this list." << endl;
    }

    return 0; // Terminate the program successfully
}
