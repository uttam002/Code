public class Solution {
    public bool CheckIfExist(int[] arr) => 
        arr.Any(m => arr.Contains(m * 2) && m != 0) || 
        arr.Count(m => m == 0) > 1;
}
