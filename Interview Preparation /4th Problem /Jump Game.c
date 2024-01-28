bool canJump(int* nums, int numsSize) {
     int index = 0,i=0;
    while (i < numsSize) {
        if (i > index) {
            return false;  // If the current index is not reachable, return false
        }
        index = (i + nums[i]) > index ? (i + nums[i]) : index;//MAIN LOGIC
        if (index >= numsSize - 1) {
            return true;  // If we can reach the end, return true
        }
        i++;
    }

    return false;  // We cannot reach the end
}
