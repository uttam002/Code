class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dp = new int[n][k + 2];
        final int INF = 1_000_000_000;
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], INF);
        }

        dp[src][0] = 0;

        for (int i = 1; i <= k + 1; i++) {
            for (int[] flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                dp[to][i] = Math.min(dp[to][i], dp[from][i - 1] + price);
            }
        }

        int minCost = INF;
        for (int i = 1; i <= k + 1; i++) {
            minCost = Math.min(minCost, dp[dst][i]);
        }

        return minCost == INF ? -1 : minCost;
     
    }
}
