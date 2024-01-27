class Solution {
    public int removeDuplicates(int[] nums) {
         HashSet<Integer> uniqueSet = new HashSet<>();
        int k = 0; // Update pointer

        for (int num : nums) {
            if (uniqueSet.add(num)) {
                nums[k++] = num;
            }
        }

        return k;
    }
}
