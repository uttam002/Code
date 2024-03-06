class Solution {
    public int minimumLength(String s) {
        int i=0,j=s.length()-1;

        while(i<j && s.charAt(i)==s.charAt(j))
        {
            char compare = s.charAt(i);

            while(i<=j && s.charAt(i)==compare)
            {
                i++;
            }

            while(i<=j && s.charAt(j)==compare)
            {
                j--;
            }
            
        }
        return j-i+1;
    }
}
