bool isSubsequence(char* s, char* t) {
    int sLen = strlen(s),tLen = strlen(t),sIndex = 0, tIndex = 0;

    while (sIndex < sLen && tIndex < tLen) if (s[sIndex] == t[tIndex++]) sIndex++;
    return sIndex == sLen;
}
