class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index=(m--)+(n--)-1;
        while(index>=0){
            if(m>=0 && n>=0){
                if(nums1[m]>nums2[n]) nums1[index--]=nums1[m--];
                else nums1[index--]=nums2[n--];
            }
            else if(m<0) nums1[index--]=nums2[n--];
            else nums1[index--]=nums1[m--];
        }
    }
}
