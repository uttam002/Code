class Solution {
    public int[] productExceptSelf(int[] nums) {
        int i=nums.length;
        int z=0;
        int product=1,temp=1;
        int[] result=new int[nums.length]; 
        for(int n:nums){
            product*=n;
        }
        if(product==0){
            for(int n:nums){
                if(n==0) {
                    z++;
                    continue;
                }
                temp*=n;
            }
        }
        for(int j=0;j<nums.length;j++){
            if(z>=2){
                result[j]=0;
            }
            if(z==1){
                if(nums[j]==0){
                  result[j]=temp;
                }
                else{
                    result[j]=0;
                }
            }
            if(z==0){
                result[j]=product/nums[j];
            }
        }
        return result;
    }
}
