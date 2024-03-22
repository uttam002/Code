int lengthOfLongestSubstring(char * s){
    int maxLength = 0,start = 0,charIndex[256];
    memset(charIndex, -1, sizeof(charIndex));
    
    for (int end = 0; s[end] != '\0'; end++) {
        if (charIndex[s[end]] >= start) start = charIndex[s[end]] + 1;
        charIndex[s[end]] = end;
        maxLength = maxLength > end - start + 1 ? maxLength : end - start + 1;
    }
    return maxLength;
}
