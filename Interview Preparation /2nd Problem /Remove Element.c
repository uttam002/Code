int i, k;

    for (i = 0, k = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }

    return k;
