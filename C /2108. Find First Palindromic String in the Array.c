int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
        if (str[i] != str[len - i - 1]) 
            return 0; 
    return 1; 
}

char* firstPalindrome(char** words, int numwords) {
    for (int i = 0; i < numwords; i++) 
        if (isPalindrome(words[i])) 
            return words[i]; 
       return ""; 
}
