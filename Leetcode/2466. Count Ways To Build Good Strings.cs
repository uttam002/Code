public class Solution
{
    private static readonly int Modulo = 1000_000_007;
    private readonly Dictionary<int, int> _memo = new();

    public int CountGoodStrings(int low, int high, int zero, int one)
    {
        return Cgs(0, low, high, zero, one);
    }

    private int Cgs(int length, int low, int high, int zero, int one)
    {
        if (length > high)
        {
            return 0;
        }

        if (_memo.ContainsKey(length))
        {
            return _memo[length];
        }

        int current = length >= low ? 1 : 0;

        int val = (current + Cgs(length + zero, low, high, zero, one)
                           + Cgs(length + one, low, high, zero, one)) % Modulo;

        _memo.Add(length, val);

        return val;
    }
}
