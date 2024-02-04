class Solution {
    public String minWindow(String s, String t) {
        int[] map = new int[128]; // Use 128 assuming ASCII characters
        int left = 0, right = 0, count = t.length(), sub_len = Integer.MAX_VALUE, start = 0;

        char[] ch = s.toCharArray();
        
        for (char c : t.toCharArray()) 
            map[c]++;

        while (right < s.length()) {
            // Decrease the count and update the frequency map
            if (map[ch[right++]]-- > 0) 
                count--;

            // Check if all characters from t are included in the current window
            while (count == 0) {
                // Update the minimum window length and starting position
                if ((right - left) < sub_len) 
                    sub_len = right - (start = left);

                // Increase count and update the frequency map
                if (map[ch[left++]]++ == 0) 
                    count++;
            }
        }

        return sub_len == Integer.MAX_VALUE ? "" : s.substring(start, start + sub_len);
    }
}
