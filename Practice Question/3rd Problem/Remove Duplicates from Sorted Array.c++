class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.unique(nums.begin(), nums.end());
        return nums.size();
    }
};
