public class Solution {
    public int IsPrefixOfWord(string sentence, string searchWord)
    {
        var v = sentence.Split(' ', StringSplitOptions.RemoveEmptyEntries).ToList();

        for (int i = 0; i < v.Count; i++)
            {
                if (v[i].StartsWith(searchWord))
                {
                    return i + 1;
                }
            }
        return -1;
    }

}
