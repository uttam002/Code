int jump(int* nums, int numsSize) {
    int ans = 0;
    int index = 0;
    int far = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        far = fmax(far,(i + nums[i]) );
        if (i == index) {
            ans++;
            index = far;
        }
    }

    return ans;
}
