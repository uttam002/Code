public class Solution {
    public int MaxScoreSightseeingPair(int[] values) {
         int maxSum = 0;
        int maxIValue = values[0]; // This represents the maximum value of values[i] + i seen so far.

        for (int j = 1; j < values.Length; j++) {
            maxSum = Math.Max(maxSum, maxIValue + values[j] - j);
            maxIValue = Math.Max(maxIValue, values[j] + j);
        }

        return maxSum;
    }
}
