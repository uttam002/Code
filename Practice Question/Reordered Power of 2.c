
void sortString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool reorderedPowerOf2(int n) {
    char num[20]; // Assuming the maximum length of the string representation of n won't exceed 20
    sprintf(num, "%d", n);
    sortString(num);
    if (n == 1)
        return true;
    int i = 2;
    while (i <= 1000000000) {
        char cur[20]; // Assuming the maximum length of the string representation of i won't exceed 20
        sprintf(cur, "%d", i);
        if (i == n)
            return true;
        sortString(cur);
        if (strcmp(cur, num) == 0)
            return true;
        i *= 2;
    }
    return false;
}
