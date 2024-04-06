char *minRemoveToMakeValid(char *s) {
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for result
    int *stack = (int *)malloc(len * sizeof(int)); // Stack to store indices of opening parentheses
    int top = -1; // Stack pointer

    // Mark indices of unmatched opening and closing parentheses
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i; // Push index of '(' into the stack
        } else if (s[i] == ')') {
            if (top >= 0 && s[stack[top]] == '(') {
                top--; // Match found, pop the corresponding '('
            } else {
                s[i] = '\0'; // Mark this ')' for removal
            }
        }
    }

    // Mark unmatched opening parentheses
    while (top >= 0) {
        s[stack[top--]] = '\0'; // Mark unmatched '(' for removal
    }

    // Copy the valid characters to the result string
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != '\0') {
            result[j++] = s[i];
        }
    }
    result[j] = '\0'; // Null-terminate the result string

    free(stack); // Free memory allocated for the stack
    return result;
}
