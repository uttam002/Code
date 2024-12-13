import java.util.*;

public class Solution {
    public long findScore(int[] arr) {
        long result = 0;
        int n = arr.length;
        
        // PriorityQueue (min-heap) to store (value, index) pairs
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1])
        );

        // Initially add all elements to the min-heap
        for (int i = 0; i < n; i++) {
            pq.add(new int[]{arr[i], i});
        }

        boolean[] visited = new boolean[n];

        while (!pq.isEmpty()) {
            // Get the minimum element (value, index)
            int[] minElem = pq.poll();
            int value = minElem[0];
            int index = minElem[1];

            if (visited[index]) continue;

            result += value;

            visited[index] = true;
            if (index - 1 >= 0) visited[index - 1] = true;
            if (index + 1 < n) visited[index + 1] = true;
        }

        return result;
    }
}
