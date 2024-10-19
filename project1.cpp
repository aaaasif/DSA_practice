#include <iostream>
#include <vector>
using namespace std;


// This function finds and prints the peak elements in the array.
// A peak element is greater than or equal to its neighbors.
// It returns the count of the peak elements found.

int findAndDisplayPeaks(vector<int>& arr, int n) {
    int peakCount = 0;

    cout << "The peak number(s) is/are: ";
     // Handle the first element separately (boundary case).
    // It's a peak if it's the only element or greater than its next element.
    if (n == 1 || arr[0] >= arr[1]) {
        cout << arr[0];
        peakCount++;
    }
        // Loop through the middle elements and check if each is a peak.
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            if (peakCount > 0) {
                cout << " -> ";
            }
            cout << arr[i]; 
            peakCount++; 
        }
    }
    if (n > 1 && arr[n - 1] >= arr[n - 2]) {
        if (peakCount > 0) {
            cout << " -> ";
        }
        cout << arr[n - 1];
        peakCount++;
    }

    cout << endl;
    return peakCount;
}

int main() {
    int n;
    cout << "What is the size of your list? " << endl;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid length!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter values of the list. You have to enter " << n << " values." << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " -> ";
        cout << arr[i];
    }
    cout << endl;
    int numberOfPeaks = findAndDisplayPeaks(arr, n);
    if (numberOfPeaks == 1) {
        cout << "There is " << numberOfPeaks << " peak in this list." << endl;
    } else {
        cout << "There are " << numberOfPeaks << " peaks in this list." << endl;
    }

    return 0;
}
