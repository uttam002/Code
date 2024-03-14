class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int res=0;
        int i=0;
        while(i<nums.length){
            int j=i;
            int temp=0;
            while(j<nums.length){
                temp=temp+nums[j];
                if(temp==goal){
                    res=res+1;
                }
                j=j+1;
            }
            i=i+1;
        }
        return res;
    }
}
