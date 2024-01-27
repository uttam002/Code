#define MOD 1000000007

int kInversePairs(int n, int k) {
    int dp[1001][1001] = {0};

    dp[1][0] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            for (int p = 0; p <= i - 1; p++) {
                if (j - p >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % MOD;
                }
            }
        }
    }

    return dp[n][k];
}
