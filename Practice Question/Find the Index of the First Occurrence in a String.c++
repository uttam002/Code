class Solution {
public:
	int strStr(string haystack, string needle) {
	   size_t s = haystack.find(needle);
	   if (s != string::npos) return int(s);
	   return -1;
	}
};
