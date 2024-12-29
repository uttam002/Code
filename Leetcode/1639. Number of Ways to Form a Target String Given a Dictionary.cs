public class Solution {
    private const int MOD = 1000000007;

    public int NumWays(string[] words, string target) {
        int tlen = target.Length;
        int wlen = words[0].Length;
        long[] res = new long[tlen + 1];
        res[0] = 1;

        for (int i = 0; i < wlen; i++) {
            // Count frequency of each character in the current column
            int[] count = new int[26];
            foreach (string word in words) {
                count[word[i] - 'a']++;
            }

            // Update the `res` array in reverse to avoid overwriting
            for (int k = tlen - 1; k >= 0; k--) {
                if (target[k] - 'a' >= 0 && target[k] - 'a' < 26) {
                    res[k + 1] += res[k] * count[target[k] - 'a'] % MOD;
                    res[k + 1] %= MOD;
                }
            }
        }

        return (int)(res[tlen] % MOD);
    }
}
