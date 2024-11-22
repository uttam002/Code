public class Solution {
    public int MaxEqualRowsAfterFlips(int[][] matrix) {
        var map = new Dictionary<string, int>();
        int ans = 0;
        foreach (var row in matrix) {
            var key = string.Join("", row.Select(cell => cell == row[0] ? 'T' : 'F'));
            map[key] = map.GetValueOrDefault(key, 0) + 1;
            ans = Math.Max(ans, map[key]);
        }
        return ans;
    }
}
