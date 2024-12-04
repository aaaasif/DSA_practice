#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& A, int K) {
    int left = 0;
    int right = A.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // To prevent overflow
        if (A[mid] == K) {
            return mid;  // Return the index of K
        } else if (A[mid] < K) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    return -1;  // K is not found
}

int main() {
    vector<int> A = {2, 3, 5, 5, 5, 7, 8};
    int K = 5;

    int result = binary_search(A, K);
    if (result != -1) {
        cout << "Value " << K << " found at index " << result << endl;
    } else {
        cout << "Value " << K << " not found." << endl;
    }
    return 0;
}
