// NAME: LONGEST INCREASING SUBSEQUENCE
// BOTH SOLUTIONS
// THIS PROBLEM HAS HISTORY MANIPULATING WITH LONG LONG CONSTRAINTS

#include <bits/stdc++.h>

using namespace std;

int LIS(int a[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++) 
            if (a[i] > a[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1; 

    int res = 0;
    for (int i = 0; i < n; i++) 
        res = max(res, lis[i]);
    
    return res;
}

// O(n*lg(n)) Time
int LIS_optimized(int a[], int n) {
    set <int> active;
    active.insert(a[0]);

    for (int i = 1; i < n; i++) {
        auto get = active.lower_bound(a[i]);
        if (get == active.end())
            active.insert(a[i]);
        // current element is the greatest so LIS increases by 1.
        else {
            int val = *get;  // we find the position where a[i] will be in the LIS. If it is in the LIS already we do nothing
            if (val > a[i]) {
                // else we remove the bigger element and add a smaller element (which is a[i]) and continue;
                active.erase(get);
                active.insert(a[i]);
            }
        }
    }
    return active.size();
}

int main() {
    int a[10] = {15, 21, 2, 3, 4, 5, 8, 4, 1, 1};
    int n = 10;

    cout << LIS(a, n) << endl;
    cout << LIS_optimized(a, n) << endl;
    
    return 0;
}