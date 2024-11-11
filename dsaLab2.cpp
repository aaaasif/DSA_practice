#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <chrono>
#include <random>

// Swap function
template <typename E>
inline void swap(E A[], int i, int j) {
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Comparator for ascending order
struct Ascending {
    template <typename E>
    static bool prior(const E& a, const E& b) {
        return a < b;
    }
};

// Insertion Sort for small arrays
template <typename E, typename Comp>
void insertionSort(E A[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        E key = A[i];
        int j = i - 1;
        while (j >= left && Comp::prior(key, A[j])) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

// Original Quicksort
template <typename E>
inline int findpivot(E A[], int i, int j) {
    return (i + j) / 2;
}

template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
    do {
        while (Comp::prior(A[++l], pivot));
        while ((l < r) && Comp::prior(pivot, A[--r]));
        swap(A, l, r);
    } while (l < r);
    return l;
}

template <typename E, typename Comp>
void qsort(E A[], int i, int j) {
    if (j <= i) return;
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j);
    int k = partition<E, Comp>(A, i - 1, j, A[j]);
    swap(A, k, j);
    qsort<E, Comp>(A, i, k - 1);
    qsort<E, Comp>(A, k + 1, j);
}

// Optimized Quicksort with median-of-three pivot
template <typename E, typename Comp>
inline int medianOfThree(E A[], int i, int j) {
    int mid = (i + j) / 2;
    if (Comp::prior(A[j], A[i])) swap(A, i, j);
    if (Comp::prior(A[mid], A[i])) swap(A, mid, i);
    if (Comp::prior(A[j], A[mid])) swap(A, j, mid);
    return mid;
}

template <typename E, typename Comp>
void qsortOptPivot(E A[], int i, int j) {
    if (j <= i) return;
    int pivotindex = medianOfThree<E, Comp>(A, i, j);
    swap(A, pivotindex, j);
    int k = partition<E, Comp>(A, i - 1, j, A[j]);
    swap(A, k, j);
    qsortOptPivot<E, Comp>(A, i, k - 1);
    qsortOptPivot<E, Comp>(A, k + 1, j);
}

// Optimized Quicksort with insertion sort for small arrays
template <typename E, typename Comp>
void qsortOptPivotAndInsertion(E A[], int i, int j, int threshold) {
    if (j - i + 1 <= threshold) {
        insertionSort<E, Comp>(A, i, j);
        return;
    }
    int pivotindex = medianOfThree<E, Comp>(A, i, j);
    swap(A, pivotindex, j);
    int k = partition<E, Comp>(A, i - 1, j, A[j]);
    swap(A, k, j);
    qsortOptPivotAndInsertion<E, Comp>(A, i, k - 1, threshold);
    qsortOptPivotAndInsertion<E, Comp>(A, k + 1, j, threshold);
}

// Iterative Quicksort using a stack
template <typename E, typename Comp>
void qsortIterative(E A[], int i, int j) {
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(i, j));

    while (!stack.empty()) {
        int start = stack.top().first;
        int end = stack.top().second;
        stack.pop();

        if (start >= end) continue;

        int pivotindex = medianOfThree<E, Comp>(A, start, end);
        swap(A, pivotindex, end);
        int k = partition<E, Comp>(A, start - 1, end, A[end]);
        swap(A, k, end);

        if (k - 1 > start) stack.push(std::make_pair(start, k - 1));
        if (k + 1 < end) stack.push(std::make_pair(k + 1, end));
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements (n >= 1000): ";
    std::cin >> n;

    if (n < 1000) {
        std::cerr << "Error: n must be at least 1000." << std::endl;
        return 1;
    }

    // Generate random data
    std::vector<int> data(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (int i = 0; i < n; ++i) {
        data[i] = dis(gen);
    }

    // Copy data for each sort
    std::vector<int> dataOriginal = data;
    std::vector<int> dataOptPivot = data;
    std::vector<int> dataOptPivotInsertion = data;
    std::vector<int> dataIterative = data;

    // Measure time for Original Quicksort
    auto start = std::chrono::high_resolution_clock::now();
    qsort<int, Ascending>(dataOriginal.data(), 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> originalTime = end - start;
    std::cout << "Original: " << originalTime.count() << " ms" << std::endl;

    // Measure time for Optimized Quicksort with median-of-three pivot
    start = std::chrono::high_resolution_clock::now();
    qsortOptPivot<int, Ascending>(dataOptPivot.data(), 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> optPivotTime = end - start;
    std::cout << "(a): " << optPivotTime.count() << " ms" << std::endl;

    // Measure time for Optimized Quicksort with insertion sort for small arrays
    start = std::chrono::high_resolution_clock::now();
    qsortOptPivotAndInsertion<int, Ascending>(dataOptPivotInsertion.data(), 0, n - 1, 10);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> optPivotInsertionTime = end - start;
    std::cout << "(a) + (b): " << optPivotInsertionTime.count() << " ms" << std::endl;

    // Measure time for Iterative Quicksort
    start = std::chrono::high_resolution_clock::now();
    qsortIterative<int, Ascending>(dataIterative.data(), 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> iterativeTime = end - start;
    std::cout << "(a) + (b) + (c): " << iterativeTime.count() << " ms" << std::endl;

    return 0;
}