#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int findPeak(vector<int>& arr, int n) {
    stack<int> peaks; 

    if (n == 1 || arr[0] >= arr[1]) {
        peaks.push(0);
    }
    if (arr[n - 1] >= arr[n - 2]) {
        peaks.push(n - 1);
    }

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            peaks.push(i);
        }
    }
    if (!peaks.empty()) {
        return peaks.top();
    }
    return -1;
}
int main() {
    int n;

    cout << "Enter the length of the array (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid length!" << endl;
        return 0;
    }
    vector<int> arr(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int peakIndex = findPeak(arr, n);
    if (peakIndex != -1) {
        cout << "Peak found at index " << peakIndex << " with value " << arr[peakIndex] << endl;
    } else {
        cout << "No peak found!" << endl;
    }
    return 0;
}
