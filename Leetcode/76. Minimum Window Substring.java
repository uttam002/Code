class Solution {
    
    public static String minWindow(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();

        // If s is shorter than t, no possible window
        if (sLen < tLen) {
            return "";
        }

        // Maps to store the count of characters in t
        Map<Character, Integer> required = new HashMap<>();
        Map<Character, Integer> current = new HashMap<>();

        // Populate the required map based on characters in t
        for (char ch : t.toCharArray()) {
            required.put(ch, required.getOrDefault(ch, 0) + 1);
        }

        // Variables for the sliding window
        int left = 0, right = 0;
        int minLen = sLen + 1, startIdx = 0, count = 0;

        // Sliding window algorithm
        while (right < sLen) {
            // Expand the window by moving the right pointer
            char rightChar = s.charAt(right);
            current.put(rightChar, current.getOrDefault(rightChar, 0) + 1);

            if (required.containsKey(rightChar) && current.get(rightChar) <= required.get(rightChar)) {
                count++;
            }

            // Contract the window by moving the left pointer
            while (count == tLen) {
                // Update the minimum window substring
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Shrink the window
                char leftChar = s.charAt(left);
                current.put(leftChar, current.get(leftChar) - 1);

                if (required.containsKey(leftChar) && current.get(leftChar) < required.get(leftChar)) {
                    count--;
                }

                // Move the left pointer
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        // If no valid window found
        if (minLen == sLen + 1) {
            return "";
        }

        // Return the result substring
        return s.substring(startIdx, startIdx + minLen);
    }

}
