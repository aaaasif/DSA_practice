#include <bits/stdc++.h>
using namespace std;

struct Ascending {
    template <typename E>
    static bool prior(const E &a, const E &b) {
        return a < b;
    }
};

template <typename E>
void swap(E A[], int i, int j) {
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename E>
inline int findpivot(E A[], int i, int j) {
    return (i + j) / 2;
}

template <typename E, typename Comp>
int partition(E A[], int left, int right, E &pivot) {
    do {
        while (Comp::prior(A[++left], pivot));
        while ((left < right) && Comp::prior(pivot, A[--right]));
        if (left < right) swap(A, left, right);
    } while (left < right);
    return left;
}

template <typename E, typename Comp>
void quicksortOriginal(E A[], int left, int right) {
    while (left < right) {
        int pivotIndex = findpivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);
        
        if (partitionIndex - left < right - partitionIndex) {
            quicksortOriginal<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortOriginal<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

template <typename E>
int medianOfThreePivot(E A[], int left, int right) {
    int mid = (left + right) / 2;
    if (A[left] > A[mid]) swap(A, left, mid);
    if (A[left] > A[right]) swap(A, left, right);
    if (A[mid] > A[right]) swap(A, mid, right);
    return mid;
}

template <typename E, typename Comp>
void quicksortMedian3(E A[], int left, int right) {
    while (left < right) {
        int pivotIndex = medianOfThreePivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        if (partitionIndex - left < right - partitionIndex) {
            quicksortMedian3<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortMedian3<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

template <typename E>
void insertionSort(E A[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        E key = A[i];
        int j = i - 1;
        while (j >= left && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

const int THRESHOLD = 30;
template <typename E, typename Comp>
void quicksortHybrid(E A[], int left, int right) {
    while (left < right) {
        if (right - left + 1 <= THRESHOLD) {
            insertionSort(A, left, right);
            return;
        }
        int pivotIndex = medianOfThreePivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        if (partitionIndex - left < right - partitionIndex) {
            quicksortHybrid<E, Comp>(A, left, partitionIndex - 1);
            left = partitionIndex + 1;
        } else {
            quicksortHybrid<E, Comp>(A, partitionIndex + 1, right);
            right = partitionIndex - 1;
        }
    }
}

template <typename E, typename Comp>
void quicksortNonRecursive(E A[], int n) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(0, n - 1));

    while (!stk.empty()) {
        int left = stk.top().first, right = stk.top().second;
        stk.pop();

        if (right - left + 1 <= THRESHOLD) {
            insertionSort(A, left, right);
            continue;
        }

        int pivotIndex = medianOfThreePivot(A, left, right);
        swap(A, pivotIndex, right);
        int partitionIndex = partition<E, Comp>(A, left - 1, right + 1, A[right]);
        swap(A, partitionIndex, right);

        if (partitionIndex - left < right - partitionIndex) {
            if (partitionIndex + 1 < right) stk.push(make_pair(partitionIndex + 1, right));
            right = partitionIndex - 1;
        } else {
            if (partitionIndex - 1 > left) stk.push(make_pair(left, partitionIndex - 1));
            left = partitionIndex + 1;
        }
    }
}

void measureSortTime(void (*sortFunction)(int*, int, int), int A[], int n, const string &label) {
    int* arr = new int[n];
    copy(A, A + n, arr);

    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    cout << label << ": " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";

    delete[] arr;
}

void measureSortTimeNonRecursive(void (*sortFunction)(int*, int), int A[], int n, const string &label) {
    int* arr = new int[n];
    copy(A, A + n, arr);

    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr, n);
    auto end = chrono::high_resolution_clock::now();
    cout << label << ": " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";

    delete[] arr;
}

int main() {
    int n;
    cout << "Enter the number of elements (n >= 1000): ";
    cin >> n;

    if (n < 1000) {
        cout << "n must be >= 1000.\n";
        return 1;
    }

    int* data = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % n;
    }

    cout << "Sorting results:\n";
    measureSortTime(quicksortOriginal<int, Ascending>, data, n, "Original ");
    measureSortTime(quicksortMedian3<int, Ascending>, data, n, "(a)");
    measureSortTime(quicksortHybrid<int, Ascending>, data, n, "(a) + (b)");
    measureSortTimeNonRecursive(quicksortNonRecursive<int, Ascending>, data, n, "(a) + (b) + (c)");

    delete[] data;
    return 0;
}