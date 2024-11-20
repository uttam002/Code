class Solution {
    public int takeCharacters(String s, int k) {
        if (k == 0) return 0;

        int[] count = new int[3]; // To count 'a', 'b', 'c'
        for (char c : s.toCharArray()) count[c - 'a']++;
        if (count[0] < k || count[1] < k || count[2] < k) return -1;

        int n = s.length(), maxLen = 0;
        int[] window = new int[3]; // Sliding window counts

        for (int l = 0, r = 0; r < n; r++) {
            window[s.charAt(r) - 'a']++;
            while (window[0] > count[0] - k || window[1] > count[1] - k || window[2] > count[2] - k) {
                window[s.charAt(l++) - 'a']--;
            }
            maxLen = Math.max(maxLen, r - l + 1);
        }

        return n - maxLen;
    }
}
