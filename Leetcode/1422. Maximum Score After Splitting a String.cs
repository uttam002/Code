public class Solution {
     public int MaxScore(string s)
    {
        int maxSum = 0;
        for (int mid = 1; mid < s.Length; mid++)
            maxSum = Math.Max(maxSum, calculateBits(s.Substring(0, mid), '0') + calculateBits(s.Substring(mid), '1'));
        return maxSum;
    }

    private int calculateBits(string s, char bitToCount)
    {
        int count = 0;
        foreach (char c in s) if (c == bitToCount) count++;
        return count;
    }
}
