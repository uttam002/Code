public class Solution {
    public int MincostTickets(int[] days, int[] costs) {
         int n = days.Length;
        int maxDay = days[n - 1];
        int[] dp = new int[maxDay + 1];
        Array.Fill(dp, int.MaxValue);
        dp[0] = 0;
        
        for (int i = 1; i <= maxDay; i++) {
            if (!days.Contains(i)) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = Math.Min(dp[i], dp[Math.Max(0, i - 1)] + costs[0]);
            dp[i] = Math.Min(dp[i], dp[Math.Max(0, i - 7)] + costs[1]);
            dp[i] = Math.Min(dp[i], dp[Math.Max(0, i - 30)] + costs[2]);
        }
        
        return dp[maxDay];
        
    }
}
