public class Solution {
    public int[] MaxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.Length;
        int[] sum = new int[n + 1], left = new int[n], right = new int[n], result = new int[3];
        
        for (int i = 0; i < n; i++) 
            sum[i + 1] = sum[i] + nums[i];

        for (int i = k, max = sum[k] - sum[0]; i < n; i++) {
            if (sum[i + 1] - sum[i + 1 - k] > max) {
                max = sum[i + 1] - sum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        right[n - k] = n - k;
        for (int i = n - k - 1, max = sum[n] - sum[n - k]; i >= 0; i--) {
            if (sum[i + k] - sum[i] >= max) {
                max = sum[i + k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int mid = sum[i + k] - sum[i];
            int total = mid + (sum[left[i - 1] + k] - sum[left[i - 1]]) + (sum[right[i + k] + k] - sum[right[i + k]]);
            if (total > maxSum) {
                maxSum = total;
                result[0] = left[i - 1];
                result[1] = i;
                result[2] = right[i + k];
            }
        }

        return result;
    }
}
