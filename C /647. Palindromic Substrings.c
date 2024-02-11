int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0; // Not a palindrome
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to count palindromic substrings
int countSubstrings(char *s) {
    int count = 0;
    int len = strlen(s);

    // Check all substrings and count palindromes
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (isPalindrome(s, i, j))
                count++;
        }
    }

    return count;
}
