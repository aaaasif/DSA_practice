#include <iostream>
#include <algorithm>
#include <stack>
#include <chrono>
#include <cstdlib>
using namespace std;

struct Comparator {
    template <typename T>
    static bool isLess(const T &a, const T &b) {
        return a < b;
    }
};

template <typename T>
void swapElements(T arr[], int idx1, int idx2) {
    T temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

template <typename T>
int choosePivot(T arr[], int low, int high) {
    return (low + high) / 2;
}

template <typename T, typename Cmp>
int partitionArray(T arr[], int low, int high, T pivot) {
    while (true) {
        while (Cmp::isLess(arr[++low], pivot));
        while (Cmp::isLess(pivot, arr[--high]));
        if (low >= high) return low;
        swapElements(arr, low, high);
    }
}

template <typename T, typename Cmp>
void quickSortClassic(T arr[], int low, int high) {
    while (low < high) {
        int pivotIdx = choosePivot(arr, low, high);
        swapElements(arr, pivotIdx, high);
        int partitionIdx = partitionArray<T, Cmp>(arr, low - 1, high + 1, arr[high]);
        swapElements(arr, partitionIdx, high);

        if (partitionIdx - low < high - partitionIdx) {
            quickSortClassic<T, Cmp>(arr, low, partitionIdx - 1);
            low = partitionIdx + 1;
        } else {
            quickSortClassic<T, Cmp>(arr, partitionIdx + 1, high);
            high = partitionIdx - 1;
        }
    }
}

template <typename T>
int medianPivot(T arr[], int low, int high) {
    int mid = (low + high) / 2;
    if (arr[low] > arr[mid]) swapElements(arr, low, mid);
    if (arr[low] > arr[high]) swapElements(arr, low, high);
    if (arr[mid] > arr[high]) swapElements(arr, mid, high);
    return mid;
}

template <typename T, typename Cmp>
void hybridQuickSort(T arr[], int low, int high, const int threshold) {
    while (low < high) {
        if (high - low + 1 <= threshold) {
            for (int i = low + 1; i <= high; i++) {
                T temp = arr[i];
                int j = i - 1;
                while (j >= low && arr[j] > temp) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = temp;
            }
            return;
        }
        int pivotIdx = medianPivot(arr, low, high);
        swapElements(arr, pivotIdx, high);
        int partitionIdx = partitionArray<T, Cmp>(arr, low - 1, high + 1, arr[high]);
        swapElements(arr, partitionIdx, high);

        if (partitionIdx - low < high - partitionIdx) {
            hybridQuickSort<T, Cmp>(arr, low, partitionIdx - 1, threshold);
            low = partitionIdx + 1;
        } else {
            hybridQuickSort<T, Cmp>(arr, partitionIdx + 1, high, threshold);
            high = partitionIdx - 1;
        }
    }
}

template <typename T, typename Cmp>
void iterativeQuickSort(T arr[], int n, const int threshold) {
    stack<pair<int, int>> ranges;
    ranges.push({0, n - 1});

    while (!ranges.empty()) {
        auto [low, high] = ranges.top();
        ranges.pop();

        if (high - low + 1 <= threshold) {
            for (int i = low + 1; i <= high; i++) {
                T temp = arr[i];
                int j = i - 1;
                while (j >= low && arr[j] > temp) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = temp;
            }
            continue;
        }

        int pivotIdx = medianPivot(arr, low, high);
        swapElements(arr, pivotIdx, high);
        int partitionIdx = partitionArray<T, Cmp>(arr, low - 1, high + 1, arr[high]);
        swapElements(arr, partitionIdx, high);

        if (partitionIdx - low < high - partitionIdx) {
            if (partitionIdx + 1 <= high) ranges.push({partitionIdx + 1, high});
            if (partitionIdx - 1 >= low) ranges.push({low, partitionIdx - 1});
        } else {
            if (partitionIdx - 1 >= low) ranges.push({low, partitionIdx - 1});
            if (partitionIdx + 1 <= high) ranges.push({partitionIdx + 1, high});
        }
    }
}

void measureSortingTime(void (*sortFunc)(int[], int, int, const int), int arr[], int n, const string &desc, int threshold) {
    int *tempArr = new int[n];
    copy(arr, arr + n, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, 0, n - 1, threshold);
    auto end = chrono::high_resolution_clock::now();

    cout << desc << ": " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
    delete[] tempArr;
}

int main() {
    int n;
    cout << "Enter number of elements (>= 1000): ";
    cin >> n;

    if (n < 1000) {
        cout << "n must be >= 1000.\n";
        return 1;
    }

    int *arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % n;

    cout << "Sorting performance:\n";
    measureSortingTime(hybridQuickSort<int, Comparator>, arr, n, "Hybrid Sort", 30);
    measureSortingTime(iterativeQuickSort<int, Comparator>, arr, n, "Iterative Sort", 30);

    delete[] arr;
    return 0;
}
