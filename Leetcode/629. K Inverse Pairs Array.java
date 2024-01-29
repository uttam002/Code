class Solution {
   static final int MODULO_VALUE = 1000000007;

    public int kInversePairs(int n, int k) {
        // Calculate maximum k
        int nKMax = (n * (n - 1)) >> 1;
        if (k > nKMax) return 0;

        // Mirror k since they are symmetric
        if ((k << 1) > nKMax) k = nKMax - k;

        // Return known value directly
        if (k == 0) return 1;
        if (k == 1) return n - 1;

        // Initialize memory array
        nKMax >>= 1;
        if (nKMax > k) nKMax = k;
        nKMax++;
        int[][] anMem = new int[2][nKMax];
        
        // Parse n = 3
        anMem[0][0] = 1;   // always 1
        anMem[0][1] = 2;   // always n - 1
        anMem[0][2] = 2;   // f(n:3, k:2) = f(n:3, k:1)
        if (nKMax > 3) anMem[0][3] = 1; // f(n:3, k:3) = f(n:3, k:0)

        anMem[1][0] = 1;   // always 1

        // Parse from n = 4
        int cIndex = 0;
        for (int i = 4; i <= n; i++) {
            cIndex ^= 1;
            int nSize = (i * (i - 1)) >> 1;

            int j = 1;
            for (; j < nKMax && j <= nSize; j++) {
                anMem[cIndex][j] = (anMem[cIndex][j - 1] + anMem[cIndex ^ 1][j]) % MODULO_VALUE;
                if (j - i >= 0) {
                    anMem[cIndex][j] -= anMem[cIndex ^ 1][j - i];
                    if (anMem[cIndex][j] < 0) anMem[cIndex][j] += MODULO_VALUE;
                }
            }
        }

        return anMem[cIndex][k];
    }

}
