public class Solution {
    public long PickGifts(int[] gifts, int k) {
        PriorityQueue<int, int> queue = new PriorityQueue<int, int>();
        foreach (int gift in gifts) {
            queue.Enqueue(gift, -gift);
        }
        
        for (int i = 0; i < k; i++) {
            int maxGift = queue.Dequeue();
            int newGift = (int)(Math.Floor(Math.Sqrt(maxGift)));
            queue.Enqueue(newGift, -newGift);
        }
        
        long sum = 0;
        while (queue.Count > 0) {
            sum += queue.Dequeue();
        }
        
        return sum;
    }
}
