public class Solution {
    public bool[] IsArraySpecial(int[] nums, int[][] queries) {
         int n = nums.Length;
        int[] arr = new int[n];
        for (int i = 1; i < n; i++) 
        {
            arr[i] = arr[i - 1];
            if ((nums[i - 1] % 2) == (nums[i] % 2)) arr[i]++;
            
        }
        bool[] result = new bool[queries.Length];
        for (int i = 0; i < queries.Length; i++) 
        {
            int from = queries[i][0];
            int to = queries[i][1];
            result[i] = arr[to] - arr[from] == 0;
        }
        return result;
    }
}
