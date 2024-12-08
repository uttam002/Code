public class Solution {
    public int MaxTwoEvents(int[][] events) {
     Array.Sort(events, (a, b) => a[1].CompareTo(b[1]));

        int maxSoFar = 0, result = 0;
        var maxValues = new List<int[]>(); 
        
        foreach (var e in events)
        {
            int maxBefore = 0;
            if (maxValues.Count > 0)
            {
                int left = 0, right = maxValues.Count - 1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (maxValues[mid][0] < e[0])
                    {
                        maxBefore = maxValues[mid][1];
                        left = mid + 1;
                    }
                    else right = mid - 1;
                }
            }

            result = Math.Max(result, e[2] + maxBefore);
            maxSoFar = Math.Max(maxSoFar, e[2]);
            maxValues.Add(new[] { e[1], maxSoFar });
        }

        return result;

    }
}
