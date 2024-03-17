import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        int i = 0, n = intervals.length;
        
        // 1. Add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) 
            res.add(intervals[i++]);
        
        // 2. Merge intervals overlapping with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[i++][1], newInterval[1]);
        }
        res.add(newInterval);
        
        // 3. Add intervals after newInterval
        while (i < n) 
            res.add(intervals[i++]);
        
        // 4. Convert list to array and return
        return res.toArray(new int[res.size()][2]);
    }
}
