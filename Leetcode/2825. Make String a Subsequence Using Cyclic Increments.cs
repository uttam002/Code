public class Solution {
    public bool CanMakeSubsequence(string s, string t) {
        return s.Aggregate(0, (i, c) => i + (i < t.Length && (t[i] - c + 26) % 26 <= 1 ? 1 : 0)) == t.Length;
    }
}
