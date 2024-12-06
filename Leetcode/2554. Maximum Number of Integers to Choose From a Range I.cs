public class Solution {
    public int MaxCount(int[] banned, int n, int maxSum) =>
    new Func<ISet<int>, int>(bannedSet =>
        Enumerable
            .Range(1, n)
            .Where(x => !bannedSet.Contains(x))
            .TakeWhile(x => (maxSum -= x) >= 0)
            .Count()
    )(banned.ToHashSet());
}
