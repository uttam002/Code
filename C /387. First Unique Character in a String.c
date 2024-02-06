int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int firstUniqChar(char* s) {
    int arr[26];
    memset(arr, -1, sizeof(arr)); // Initialize to -1
    int n = 26;
    for (int i = 0; s[i]!='\0'; i++) {
            char c = s[i];
            if (arr[c - 'a'] != -1) {
                arr[c - 'a'] = -2;
                continue;
            } else {
                arr[c - 'a'] = i;
            }
        }
        qsort(arr, n, sizeof(int), compare);
        for (int i = 0; i < 26; i++) {
            if (arr[i] >= 0) {
                return arr[i];
            }
        }
        return -1;
}
