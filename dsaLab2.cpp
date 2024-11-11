#include <bits/stdc++.h>
using namespace std;

// Comparator for ascending order
struct Ascending {
    template <typename E>
    static bool prior(const E &a, const E &b) {
        return a < b; // Returns true if 'a' is less than 'b'
    }
};

// Swap function to exchange two elements in an array
template <typename E>
void swap(E A[], int i, int j) {
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Function to find the pivot index (middle element)
template <typename E>
inline int findpivot(E A[], int i, int j) {
    return (i + j) / 2; // Return the index of the middle element
}

// Partition function for quicksort
// Rearranges elements around a pivot
template <typename E, typename Comp>
int partition(E A[], int left, int right, E &pivot) {
    do {
        // Move left pointer to the right until an element >= pivot is found
        while (Comp::prior(A[++left], pivot));
        // Move right pointer to the left until an element <= pivot is found
        while ((left < right) && Comp::prior(pivot, A[--right]));
        // Swap elements if left is still less than right
        if (left < right) swap(A, left, right);
    } while (left < right);
    return left; // Return the partition index
}

// Recursive implementation of the original quicksort algorithm
template <typename E, typename Comp>
void quicksortOriginal(E A[], int left, int right) {
    while (left < right) {
        // Find the pivot and swap it with the rightmost element
        int pivotIndex = findpivot(A, left, right);
        swap(A, pivotIndex, right);
        // Partition the array and get the partition index
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        // Recursively sort the smaller partition first to optimize stack usage
        if (partitionIndex - left < right - partitionIndex) {
            quicksortOriginal<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortOriginal<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

// Median-of-three pivot selection to improve pivot choice
template <typename E>
int medianOfThreePivot(E A[], int left, int right) {
    int mid = (left + right) / 2;
    // Ensure the order: A[left] <= A[mid] <= A[right]
    if (A[left] > A[mid]) swap(A, left, mid);
    if (A[left] > A[right]) swap(A, left, right);
    if (A[mid] > A[right]) swap(A, mid, right);
    return mid; // Return the index of the median
}

// Quicksort implementation with median-of-three pivot selection
template <typename E, typename Comp>
void quicksortMedian3(E A[], int left, int right) {
    while (left < right) {
        int pivotIndex = medianOfThreePivot(A, left, right); // Use median-of-three
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        // Recursively sort the smaller partition first
        if (partitionIndex - left < right - partitionIndex) {
            quicksortMedian3<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortMedian3<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

// Insertion sort for small subarrays
template <typename E>
void insertionSort(E A[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        E key = A[i];
        int j = i - 1;
        // Shift elements to the right until the correct position is found
        while (j >= left && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

// Threshold for switching to insertion sort
const int THRESHOLD = 30;

// Hybrid quicksort: Uses insertion sort for small subarrays
template <typename E, typename Comp>
void quicksortHybrid(E A[], int left, int right) {
    while (left < right) {
        // Switch to insertion sort for small subarrays
        if (right - left + 1 <= THRESHOLD) {
            insertionSort(A, left, right);
            return;
        }
        int pivotIndex = medianOfThreePivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        // Recursively sort the smaller partition first
        if (partitionIndex - left < right - partitionIndex) {
            quicksortHybrid<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortHybrid<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

// Non-recursive quicksort using an explicit stack
template <typename E, typename Comp>
void quicksortNonRecursive(E A[], int n) {
    stack<pair<int, int>> stk; // Stack to hold subarray boundaries
    stk.push(make_pair(0, n - 1));

    while (!stk.empty()) {
        int left = stk.top().first, right = stk.top().second;
        stk.pop();

        if (right - left + 1 <= THRESHOLD) {
            insertionSort(A, left, right); // Use insertion sort for small subarrays
            continue;
        }

        int pivotIndex = medianOfThreePivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        // Push larger partition onto the stack to reduce stack depth
        if (partitionIndex - left < right - partitionIndex) {
            if (partitionIndex + 1 < right) stk.push(make_pair(partitionIndex + 1, right));
            right = partitionIndex - 1;
        } else {
            if (partitionIndex - 1 > left) stk.push(make_pair(left, partitionIndex - 1));
            left = partitionIndex + 1;
        }
    }
}

// Function to measure the execution time of sorting algorithms
void measureSortTime(void (*sortFunction)(int*, int, int), int A[], int n, const string &label) {
    int* arr = new int[n];
    copy(A, A + n, arr); // Copy the original array to avoid modifying it

    auto start = chrono::high_resolution_clock::now(); // Start timer
    sortFunction(arr, 0, n - 1); // Call the sorting function
    auto end = chrono::high_resolution_clock::now(); // End timer
    cout << label << ": " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";

    delete[] arr; // Free allocated memory
}

// Overloaded function to measure execution time for non-recursive quicksort
void measureSortTimeNonRecursive(void (*sortFunction)(int*, int), int A[], int n, const string &label) {
    int* arr = new int[n];
    copy(A, A + n, arr);

    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr, n);
    auto end = chrono::high_resolution_clock::now();
    cout << label << ": " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";

    delete[] arr;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements (n >= 1000): ";
    cin >> n;

    if (n < 1000) {
        cout << "n must be >= 1000.\n";
        return 1;
    }

    // Generate random data
    int* data = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % n;
    }

    // Measure and compare sorting times
    cout << "Sorting results:\n";
    measureSortTime(quicksortOriginal<int, Ascending>, data, n, "Original ");
    measureSortTime(quicksortMedian3<int, Ascending>, data, n, "(a)");
    measureSortTime(quicksortHybrid<int, Ascending>, data, n, "(a) + (b)");
    measureSortTimeNonRecursive(quicksortNonRecursive<int, Ascending>, data, n, "(a) + (b) + (c)");

    delete[] data; // Free allocated memory
    return 0;
}
