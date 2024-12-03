public class Solution
{
    public string AddSpaces(string s, int[] spaces)
    {
        StringBuilder sb = new StringBuilder(s);
        int i=0;
        foreach (int space in spaces)
            sb.Insert(space+(i++), " ");
        return sb.ToString();
    }
}
