class Solution {
    public int maxFrequencyElements(int[] nums) {
        int maxi = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            maxi = Math.max(maxi, map.get(nums[i]));
        }

        int res = 0;
        for (int keys : map.keySet()) {
            if (map.get(keys) == maxi)
                res += map.get(keys);
        }
        return res;
    }
}
