// NAME: EDIT DISTANCE
// O(N^2)

#include <bits/stdc++.h>

using namespace std;

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int editDist(string str1, string str2, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    // If last characters are same
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
    // Remaining 3 cases
    return 1 + min3(editDist(str1, str2, m, n - 1),
                   editDist(str1, str2, m - 1, n),
                   editDist(str1, str2, m - 1, n - 1));
}

int editDistDP(string str1, string str2, int m, int n) {
    int dp[m + 1][n + 1]; // bottom up
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min3(dp[i][j - 1],    // Insert
                                   dp[i - 1][j],     // Remove
                                   dp[i - 1][j - 1]  // Replace
                               );
        }
    return dp[m][n];
}

int main() {
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2, str1.length(), str2.length()) << endl;
    cout << editDistDP(str1, str2, str1.length(), str2.length()) << endl;

    return 0;
}