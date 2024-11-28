class Solution {
    class Pair implements Comparable<Pair> {
        int row, col, path;
        Pair(int r, int c, int p) { row = r; col = c; path = p; }
        public int compareTo(Pair p) { return path - p.path; }
    }

    private void relax(int[][] grid, int[][] dist, PriorityQueue<Pair> pq, int r, int c, int nr, int nc) {
        if (nr >= 0 && nc >= 0 && nr < grid.length && nc < grid[0].length &&
            dist[r][c] + grid[nr][nc] < dist[nr][nc]) {
            dist[nr][nc] = dist[r][c] + grid[nr][nc];
            pq.add(new Pair(nr, nc, dist[nr][nc]));
        }
    }

    public int minimumObstacles(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[][] dist = new int[rows][cols] ;
        for (int[] d : dist) java.util.Arrays.fill(d, Integer.MAX_VALUE);
        dist[0][0] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, 0, 0));
        boolean[][] vis = new boolean[rows][cols];

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int r = curr.row, c = curr.col;
            if (vis[r][c]) continue;
            vis[r][c] = true;

            relax(grid, dist, pq, r, c, r - 1, c);
            relax(grid, dist, pq, r, c, r + 1, c);
            relax(grid, dist, pq, r, c, r, c - 1);
            relax(grid, dist, pq, r, c, r, c + 1);
        }
        return dist[rows - 1][cols - 1];
    }
}
