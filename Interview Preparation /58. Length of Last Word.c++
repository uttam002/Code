class Solution {
public:
	int lengthOfLastWord(string s) {
		int l = 0,i = s.length() - 1;
		while (i>=0)
		{
			if (s[i] == ' ') i--;
			if (s[i] != ' ')
			{
				l++;
				i--;
                if(i<0) return l;
			}
			if (s[i] == ' ' && l != 0) return l;
		}
		return l;
	}
};
