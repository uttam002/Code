class Solution {
    public int[] rearrangeArray(int[] nums) {
      int[] result = new int[nums.length];
      int x=-2,y=-1;
      for(int i=0;i<nums.length;i++){
          if(nums[i]>0)result[x+=2]=nums[i];
          else result[y+=2]=nums[i];
      }
      return result;
    }
}
