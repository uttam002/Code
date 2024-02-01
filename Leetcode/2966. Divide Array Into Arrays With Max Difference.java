// import java.util.Arrays;

public class Solution {
    
    // Method to divide the array into subarrays
    public static int[][] divideArray(int[] nums, int k) {
        // Check if nums is null or empty
        if (nums == null || nums.length == 0) {
            return null;
        }

        // Sort the array in ascending order
        Arrays.sort(nums);
        
        // Calculate the number of subarrays needed
        int numSubarrays = nums.length / 3;

        // Initialize the 2D array to store subarrays
        int[][] output = new int[numSubarrays][3];

        // Populate the 2D array with subarrays
        int m = 0;
        for (int i = 0; i < numSubarrays; i++) {
            for (int j = 0; j < 3; j++) {
                output[i][j] = nums[m];
                m++;
            }
        }

        // Check if the constraint is satisfied for each subarray
        for (int i = 0; i < numSubarrays; i++) {
            if (output[i][2] - output[i][0] > k) {
                // Constraint not satisfied, return an empty array
                return new int[0][];
            }
        }

        // Return the populated 2D array of subarrays
        return output;
    }
}
