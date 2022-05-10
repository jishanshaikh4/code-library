// NAME: MATRIX CHAIN MULTIPLICATION

#include <bits/stdc++.h>

using namespace std;

#define MAX 10

int dp[MAX][MAX];

int matrixChainMultiplication(int dim[], int i, int j) {
    if (j <= i + 1) // one matrix?
        return 0;
    int min = INT_MAX;
    if (dp[i][j] == 0) {
        // take the minimum over each possible position at which the sequence of matrices can be split (for ixj and jxk to ixk)
        for (int k = i + 1; k <= j - 1; k++) {
            int cost = matrixChainMultiplication(dim, i, k);
            cost += matrixChainMultiplication(dim, k, j);
            cost += dim[i] * dim[k] * dim[j];
            if (cost < min)
                min = cost;
        }
        dp[i][j] = min;
    }
    return dp[i][j];
}

int main() {
    int dim[] = {10, 30, 5, 60};
    int n = 4;

    cout << matrixChainMultiplication(dim, 0, n - 1) << endl;

    return 0;
}