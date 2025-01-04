using System;
using System.Linq;

public class Solution
{
    public int CountPalindromicSubsequence(string s)
    {
        int[] first = Enumerable.Repeat(int.MaxValue, 26).ToArray();
        int[] last = new int[26];
        int res = 0;

        for (int i = 0; i < s.Length; ++i)
        {
            first[s[i] - 'a'] = Math.Min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (first[i] < last[i])
            {
                var middle = s.Substring(first[i] + 1, last[i] - first[i] - 1);
                res += middle.Distinct().Count();
            }
        }

        return res;
    }
}
