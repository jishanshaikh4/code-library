// PROBLEM: COIN CHANGE
// BOTTON UP DP

#include <bits/stdc++.h>

using namespace std;

int coinChange(int arr[], int n, int N) {
    // dp[i] = no of coins required to get a total of i
    int dp[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = INT_MAX;
        int res = INT_MAX;

        for (int c = 0; c < n; c++) {
            if (i - arr[c] >= 0)  // check if coins doesn't become negative by including it
                res = dp[i - arr[c]];
            // if total can be reached by including current coin c, update minimum number of coins needed dp[i]
            if (res != INT_MAX)
                dp[i] = min(dp[i], res + 1);
        }
    }
    return dp[N];
}

int coinChange_topDown(int n, int coins[], int N, int dp[]) {
    if (n == 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (n - coins[i] >= 0) {
            int sub = coinChange_topDown(n - coins[i], coins, N, dp);
            ans = min(ans, sub + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int N = 15;
    
    cout << coinChange(arr, n, N) << endl;

    return 0;
}