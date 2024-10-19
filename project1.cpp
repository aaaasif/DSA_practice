#include <iostream>
#include <vector>
using namespace std;


// This function finds and prints the peak elements in the array.
// A peak element is greater than or equal to its neighbors.
// code returns the count of the peak elements found.

int findAndDisplayPeaks(vector<int>& arr, int n) {
    int peakCount = 0;

    cout << "The peak number(s) is/are: ";
     // Handle the first element separately.
    // It's a peak if it's the only element or greater than its next element.
    if (n == 1 || arr[0] >= arr[1]) {
        cout << arr[0];
        peakCount++;
    }
    // Loop through the middle elements and check if each is a peak.
    for (int i = 1; i < n - 1; i++) {
        // An element is a peak if it's greater than or equal to its neighbors.
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            if (peakCount > 0) {
                cout << " -> "; // To format the output properly if there are multiple peaks.
            }
            cout << arr[i]; 
            peakCount++; 
        }
    }
    // Handle the last element separately.
    // It's a peak if it's greater than or equal to its previous element.
    if (n > 1 && arr[n - 1] >= arr[n - 2]) {
        if (peakCount > 0) {
            cout << " -> ";  //To format the output for multiple peaks.
        }
        cout << arr[n - 1];
        peakCount++;
    }

    cout << endl;
    return peakCount;
}

int main() {
    int n;
        // Prompt user for the size of the list.
    cout << "What is the size of your list? " << endl;
    cin >> n;
    // Handle invalid input for the list size.
    if (n <= 0) {
        cout << "Invalid length!" << endl;
        return 0;
    }

    vector<int> arr(n);
    //user to enter the values of the list.
    cout << "Enter values of the list. You have to enter " << n << " values." << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // Input the elements into the vector.
    }
    // Display the entire list with proper formatting.
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " -> ";   // Print arrows between the values.
        cout << arr[i];
    }
    cout << endl;
        // Find and display the peaks, then print the count of peaks.
    int numberOfPeaks = findAndDisplayPeaks(arr, n);
      // Output the number of peaks with correct singular/plural grammar.
    if (numberOfPeaks == 1) {
        cout << "There is " << numberOfPeaks << " peak in this list." << endl;
    } else {
        cout << "There are " << numberOfPeaks << " peaks in this list." << endl;
    }

    return 0; //print the output
}
