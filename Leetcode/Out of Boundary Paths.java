class Solution {
    private static final int MOD = 1_000_000_007;
     public static int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       int[][][] dp = new int[maxMove + 1][m][n];
        dp[0][startRow][startColumn] = 1;

        int result = 0;

        for (int move = 1; move <= maxMove; move++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[move - 1][i][j] > 0) {
                        int[] dir = {-1, 0, 1, 0, -1};
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dir[d];
                            int nj = j + dir[d + 1];
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                                dp[move][ni][nj] = (dp[move][ni][nj] + dp[move - 1][i][j]) % MOD;
                            } else {
                                result = (result + dp[move - 1][i][j]) % MOD;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
}
