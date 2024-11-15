class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, left = 0, right = n - 1;
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;
        if (left == n - 1) return 0;
        while (right > left && arr[right - 1] <= arr[right]) right--;
        int result = Math.min(n - left - 1, right), i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) { result = Math.min(result, j - i - 1); i++; }
            else j++;
        }
        return result;
    }
}
