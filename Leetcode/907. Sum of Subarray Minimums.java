class Solution {
    public int sumSubarrayMins(int[] arr) {
        int MOD = 1000000007;
        int n = arr.length;
        long result = 0;

        // Arrays to store the left and right smaller elements
        int[] left = new int[n];
        int[] right = new int[n];

        // Calculate left smaller elements
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && arr[i] < arr[j]) {
                j = left[j];
            }
            left[i] = j;
        }

        // Calculate right smaller elements
        for (int i = n - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < n && arr[i] <= arr[j]) {
                j = right[j];
            }
            right[i] = j;
        }

        // Calculate the contribution of each element to the final result
        for (int i = 0; i < n; i++) {
            result = (result + (long) arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }

        return (int) result;
    }
}
