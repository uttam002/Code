public class Solution {
    public int MaximumLength(string s) {
        int n = s.Length;
        int left = 1, right = n;
        int result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (HasSpecialSubstringOfLength(s, mid)) {
                result = mid; 
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }

        return result;
    }
    private bool HasSpecialSubstringOfLength(string s, int len) {
        Dictionary<long, int> hashCount = new Dictionary<long, int>();
        long hash = 0;
        long baseValue = 31; 
        long mod = 1000000007; 

        long basePower = 1;
        for (int i = 1; i < len; i++) {
            basePower = (basePower * baseValue) % mod;
        }

        for (int i = 0; i < len; i++) {
            hash = (hash * baseValue + (s[i] - 'a' + 1)) % mod;
        }
        hashCount[hash] = 1;
        for (int i = len; i < s.Length; i++) {
            hash = (hash - (s[i - len] - 'a' + 1) * basePower % mod + mod) % mod;
            hash = (hash * baseValue + (s[i] - 'a' + 1)) % mod;

            if (IsSpecial(s, i - len + 1, i)) {
                if (!hashCount.ContainsKey(hash)) {
                    hashCount[hash] = 0;
                }
                hashCount[hash]++;
                if (hashCount[hash] >= 3) {
                    return true;
                }
            }
        }

        return false;
    }
    private bool IsSpecial(string s, int start, int end) {
        char firstChar = s[start];
        for (int i = start; i <= end; i++) {
            if (s[i] != firstChar) {
                return false;
            }
        }
        return true;
    }
}
