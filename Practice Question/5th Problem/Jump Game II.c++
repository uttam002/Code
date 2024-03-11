class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0,n = nums.size(),End = 0,Far = 0;
        for (int i = 0; i < n - 1; i++) {
        Far = max(Far, i + nums[i]);
        if (i == End) {
            ans++;
            End = Far;
        }
    }
    return ans;
    }
};
