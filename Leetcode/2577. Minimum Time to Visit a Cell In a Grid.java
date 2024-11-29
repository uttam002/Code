class Solution {
    public int minimumTime(int[][] grid) {
        
        if(grid[0][1]>1 && grid[1][0] > 1){
            return -1;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0]-b[0]);
        pq.offer(new int[]{0,0,0});

        int[][] dirs = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
        int r = grid.length, c = grid[0].length;
        boolean[][] vis = new boolean[r][c];
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            if(cur[1]==r-1 && cur[2]==c-1){
                return cur[0];
            }
            if(vis[cur[1]][cur[2]]){
                continue;
            }
            vis[cur[1]][cur[2]] = true;
            for(int d[] : dirs){
                int ni = cur[1]+d[0];
                int nj = cur[2]+d[1];
                if(ni>=0 && nj >= 0 && ni<r && nj < c && !vis[ni][nj]){
                    int time = grid[ni][nj];
                    int timed = time-cur[0];
                    if(timed>0){
                        time += (timed%2 == 0 ? 1 : 0);
                    }else{
                        time = cur[0]+1;
                    }
                    pq.offer(new int[]{time,ni,nj});
                }
            }
        }
        return -1;

    }
}
