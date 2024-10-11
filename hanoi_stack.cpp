#include <bits/stdc++.h>
using namespace std;

void solveTowerOfHanoi(int n, char sourceRod, char targetRod, char auxiliaryRod) {
    if (n <= 0) 
    {
        return;
    }
    solveTowerOfHanoi(n - 1, sourceRod, auxiliaryRod, targetRod);
    cout << "Move disk " << n << " from rod " << sourceRod << " to rod " << targetRod << endl; // Move nth disk
    solveTowerOfHanoi(n - 1, auxiliaryRod, targetRod, sourceRod);
}

int main() {
    int N; 
    cout << "Enter the number of disks = ";
    cin >> N;
    solveTowerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
