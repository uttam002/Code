public class Solution {
    public int[] LeftmostBuildingQueries(int[] buildingHeights, int[][] queries) {
        int totalBuildings = buildingHeights.Length;
        int[,] sparseTable = new int[totalBuildings, 20];
        int[] logValues = new int[totalBuildings + 1];
        logValues[0] = -1;

        // Precompute logarithms
        for (int i = 1; i <= totalBuildings; i++) {
            logValues[i] = logValues[i >> 1] + 1;
        }

        // Build Sparse Table for range maximum queries
        for (int i = 0; i < totalBuildings; i++) {
            sparseTable[i, 0] = buildingHeights[i];
        }

        for (int power = 1; power < 20; power++) {
            for (int i = 0; i + (1 << power) <= totalBuildings; i++) {
                sparseTable[i, power] = Math.Max(sparseTable[i, power - 1], sparseTable[i + (1 << (power - 1)), power - 1]);
            }
        }

        int queryCount = queries.Length;
        int[] result = new int[queryCount];

        // Process each query
        for (int qIndex = 0; qIndex < queryCount; qIndex++) {
            int left = queries[qIndex][0], right = queries[qIndex][1];
            if (left > right) {
                // Swap left and right if they are in the wrong order
                int temp = left;
                left = right;
                right = temp;
            }

            // If the query range is a single building, return that building
            if (left == right) {
                result[qIndex] = left;
                continue;
            }

            // If the building at 'right' is taller than 'left', return 'right'
            if (buildingHeights[right] > buildingHeights[left]) {
                result[qIndex] = right;
                continue;
            }

            // Find the maximum height at both 'left' and 'right'
            int maxHeight = Math.Max(buildingHeights[left], buildingHeights[right]);
            int low = right + 1, high = totalBuildings, mid;

            // Binary search to find the first building taller than the current maximum
            while (low < high) {
                mid = (low + high) / 2;
                int logValue = logValues[mid - right + 1];
                int maxInRange = Math.Max(sparseTable[right, logValue], sparseTable[mid - (1 << logValue) + 1, logValue]);

                if (maxInRange > maxHeight) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            // If no taller building is found, return -1
            result[qIndex] = (low == totalBuildings) ? -1 : low;
        }

        return result;
    }
}
