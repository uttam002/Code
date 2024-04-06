class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder result = new StringBuilder();
        int openCount = 0; // Count of '('
        
        // First pass: remove extra ')'
        for (char ch : s.toCharArray()) {
            if (ch == '(') openCount++;
            else if (ch == ')') {
                if (openCount == 0) continue; // Skip this ')', it's extra
                openCount--;
            }
            result.append(ch);
        }
        
        StringBuilder finalResult = new StringBuilder();

        // Second pass: remove extra '('
        for (int i = result.length() - 1; i >= 0; i--) {
            char ch = result.charAt(i);
            if (ch == '(' && openCount > 0) {
                openCount--;
                continue; // Skip this '(', it's extra
            }
            finalResult.append(ch);
        }
        
        return finalResult.reverse().toString();
    }
}
