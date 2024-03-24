int findDuplicate(int* nums, int numsSize) {
    // Initialize slow and fast pointers
    int slowPointer = nums[0];
    int fastPointer = nums[0];

    // Move slow pointer one step and fast pointer two steps
    // until they meet inside the cycle
    do {
        slowPointer = nums[slowPointer];
        fastPointer = nums[nums[fastPointer]];
    } while (slowPointer != fastPointer);

    // Reset one pointer to the start of the array and move both pointers
    // at the same pace until they meet at the entrance of the cycle
    slowPointer = nums[0];
    while (slowPointer != fastPointer) {
        slowPointer = nums[slowPointer];
        fastPointer = nums[fastPointer];
    }

    // Return the duplicate number
    return slowPointer;
}
