int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
        int count = 1;

        // Boyer-Moore Voting Algorithm
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
            
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }  
        }

        return candidate;
}

