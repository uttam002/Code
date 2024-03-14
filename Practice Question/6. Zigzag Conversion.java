class Solution {
    public String convert(String s, int numRows) {
        if (numRows >= s.length() || numRows == 1)
            return s;

        StringBuilder[] str = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++)             
            str[i] = new StringBuilder();
        
        int a = 0;
        boolean b = false;

        for (int i = 0; i < s.length(); i++) {
            str[a].append(s.charAt(i));

            if (a == 0)                b = false;
            if (a == numRows - 1)      b = true;
            if (b == true)             a--;
            else                       a++;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < numRows; i++)
            ans.append(str[i]);

        return ans.toString();
    
    }
}
