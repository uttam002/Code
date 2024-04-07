class Solution {
    public boolean checkValidString(String s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                minOpen++;
                maxOpen++;
            } else if (ch == ')') {
                if (minOpen > 0) {
                    minOpen--;
                }
                maxOpen--;
            } else { // wildcard character '*'
                if (minOpen > 0) {
                    minOpen--;
                }
                maxOpen++;
            }
            
            if (maxOpen < 0) {
                return false;
            }
        }

        return minOpen == 0;
    }
}
