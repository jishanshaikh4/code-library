// Overlapping subproblems
// Optimal substructure
// Recursion?
// Top-down and bottom-up
// O(n^2) to O(n*logn)
// Practice problems: standard ones + their variations

#include <bits/stdc++.h>

using namespace std;

int fibonacciBottomUp(int n) {
    int res[3];
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i <= n; i++) {
        res[2] = res[1] + res[0];
        res[0] = res[1];
        res[1] = res[2];
    }
    return res[1];
}

int main() {
    int n = 21;
    
    cout << fibonacciBottomUp(n) << endl;
    
    return 0;
}