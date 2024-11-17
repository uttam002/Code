class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length, res = n + 1;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i <= n; i++) {
            while (!deque.isEmpty() && prefix[i] - prefix[deque.peekFirst()] >= k)
                res = Math.min(res, i - deque.pollFirst());
            while (!deque.isEmpty() && prefix[i] <= prefix[deque.peekLast()])
                deque.pollLast();
            deque.addLast(i);
        }
        return res <= n ? res : -1;
    }
}
