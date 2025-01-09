public class Solution {
    public int PrefixCount(string[] words, string pref) {
         return words.Count(word => word.StartsWith(pref, StringComparison.OrdinalIgnoreCase));
    }
}
