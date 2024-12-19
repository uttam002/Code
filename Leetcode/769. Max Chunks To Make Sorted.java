class Solution {
    public int maxChunksToSorted(int[] arr) {
         int count = 0;
        int n = arr.length;
        
        // Step 1: Compute prefix maximum
        int[] prefix = new int[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = Math.max(arr[i], prefix[i - 1]);
        }
        
        // Step 2: Sort the array
        int[] temp = arr.clone();
        Arrays.sort(temp);
        
        // Step 3: Compare prefix maximum with sorted array
        for (int i = 0; i < n; i++) {
            if (prefix[i] == temp[i]) {
                count++;
            }
        }
        
        return count;
    }
}
