void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i1 = m - 1;
    int i2 = n - 1;
    int i = m + n - 1;
    while(i2 >= 0)
    {
        if (i1 < 0 || nums1[i1] <= nums2[i2]) nums1[i--] = nums2[i2--];
        else nums1[i--] = nums1[i1--];
    }
}
