public class Solution {
    public bool CanConstruct(string s, int k) {
        if(k>s.Length) return false;
        int[] note = new int[26];
        // note = {0};
        foreach(char c in s){
            note[c-'a']++;
        }
        int count=0;
        foreach(int i in note){
            if(i%2!=0)count++;
            if(count>k)return false;
        }
        return true;
    }
}
