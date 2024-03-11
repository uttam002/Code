public class Solution {
    public String customSortString(String order, String s) {
        // Step 1: Initialize an array to count occurrences of characters in s
        int[] arr = new int[26]; // Assuming lowercase English letters only
        
        // Step 2: Count occurrences of each character in s
        for (char c : s.toCharArray()) {
            arr[c - 'a']++; // Increment count at the index corresponding to the character
        }

        // StringBuilder to construct the result string
        StringBuilder sb = new StringBuilder();
        
        // Step 3: Construct the result string based on the order
        for (char c : order.toCharArray()) {
            while (arr[c - 'a'] > 0) {
                sb.append(c); // Append character to the result string
                arr[c - 'a']--; // Decrement count of the character
            }
        }

        // Step 4: Append any remaining characters from s
        for (int i = 0; i < 26; i++) {
            while (arr[i] > 0) {
                sb.append((char) (i + 'a')); // Append character to the result string
                arr[i]--; // Decrement count of the character
            }
        }

        // Step 5: Return the resulting string
        return sb.toString();
    }
}
