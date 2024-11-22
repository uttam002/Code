class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> map = new HashMap<>();
        int ans = 0;
        for (int[] row : matrix) {
            StringBuilder sb = new StringBuilder();
            for (int cell : row) sb.append(cell == row[0] ? 'T' : 'F');
            ans = Math.max(ans, map.merge(sb.toString(), 1, Integer::sum));
        }
        return ans;
    }
}
