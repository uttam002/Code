class Solution {
    public boolean canJump(int[] nums) {
        // Initialize the index to the last element of the array
        int index = nums.length - 1;
        
        // Iterate backward through the array starting from the second-to-last element
        for (int i = nums.length - 1; i >= 0; i--) {
            // Calculate the maximum reachable index from the current position
            int j = nums[i] + i;
            
            // If the maximum reachable index from the current position is greater than or equal to the current index,
            // update the index to the current position (indicating that it's a valid jump)
            if (j >= index) {
                index = i;
            }
        }
        
        // After the loop, check if the final index is at the beginning of the array (position 0)
        return index == 0;
    }
}
