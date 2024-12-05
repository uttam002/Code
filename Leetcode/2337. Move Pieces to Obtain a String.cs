public class Solution {
    public bool CanChange(string start, string target) =>
        start.Replace("_", "") == target.Replace("_", "") &&
        target.IndexOf('L') <= start.IndexOf('L') &&
        start.IndexOf('R') <= target.IndexOf('R') &&
        start.LastIndexOf('R') <= target.LastIndexOf('R') &&
        target.LastIndexOf('L') <= start.LastIndexOf('L');
}
