public class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2;
            int storesNeeded = 0;
            for (int q : quantities) {
                storesNeeded += (q + mid - 1) / mid;
            }
            if (storesNeeded > n) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}
