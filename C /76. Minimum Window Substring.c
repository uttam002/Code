
#define MAX_CHARS 256

// Function to find the minimum window substring
char* minWindow(char* s, char* t) {
    // Lengths of input strings
    int sLen = strlen(s);
    int tLen = strlen(t);

    // If s is shorter than t, no possible window
    if (sLen < tLen) {
        return "";
    }

    // Arrays to store the count of characters in t
    int required[MAX_CHARS] = {0};
    int current[MAX_CHARS] = {0};

    // Populate the required array based on characters in t
    for (int i = 0; i < tLen; i++) {
        required[t[i]]++;
    }

    // Variables for the sliding window
    int left = 0, right = 0;
    int minLen = sLen + 1, startIdx = 0, count = 0;

    // Sliding window algorithm
    while (right < sLen) {
        // Expand the window by moving the right pointer
        if (required[s[right]] > 0) {
            current[s[right]]++;
            if (current[s[right]] <= required[s[right]]) {
                count++;
            }
        }

        // Contract the window by moving the left pointer
        while (count == tLen) {
            // Update the minimum window substring
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            // Shrink the window
            if (required[s[left]] > 0) {
                current[s[left]]--;
                if (current[s[left]] < required[s[left]]) {
                    count--;
                }
            }

            // Move the left pointer
            left++;
        }

        // Move the right pointer to expand the window
        right++;
    }

    // If no valid window found
    if (minLen == sLen + 1) {
        return "";
    }

    // Allocate memory for the result substring
    char* result = malloc((minLen + 1) * sizeof(char));

    // Copy the result substring to the allocated memory
    strncpy(result, s + startIdx, minLen);

    // Null-terminate the result string
    result[minLen] = '\0';

    // Return the result substring
    return result;
}

