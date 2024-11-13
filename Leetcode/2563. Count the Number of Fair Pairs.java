public class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums); // Sort the array to use binary search effectively
        long count = 0;
        
        for (int i = 0; i < nums.length; i++) {
            int minJ = findLowerBound(nums, i + 1, nums.length - 1, lower - nums[i]);
            int maxJ = findUpperBound(nums, i + 1, nums.length - 1, upper - nums[i]);
            if (minJ != -1 && maxJ != -1 && minJ <= maxJ) {
                count += (maxJ - minJ + 1);
            }
        }
        
        return count;
    }

    // Binary search for the first index where nums[i] + nums[j] >= lower
    private int findLowerBound(int[] nums, int start, int end, int target) {
        int left = start, right = end;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left <= end ? left : -1;
    }

    // Binary search for the last index where nums[i] + nums[j] <= upper
    private int findUpperBound(int[] nums, int start, int end, int target) {
        int left = start, right = end;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right >= start ? right : -1;
    }
}
