struct Map{
    int freq;
    char ch;
};


int compare(const void *a, const void *b) {
    struct Map *mapA = (struct Map *)a;
    struct Map *mapB = (struct Map *)b;
    return mapB->freq - mapA->freq;
}
char* frequencySort(char* s) {
    int n = strlen(s);
    struct Map map[128] = {0}; // Assumes ASCII characters

    // Calculate frequency of each character
    for (int i = 0; i < n; i++) {
        map[(int)s[i]].ch = s[i];
        map[(int)s[i]].freq++;
    }

    // Sort characters by frequency using qsort
    qsort(map, 128, sizeof(struct Map), compare);

    // Create a new string with characters sorted by frequency
    char *result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < 128; i++) { // Iterate up to 256
        if (map[i].freq > 0) {
            memset(result + index, map[i].ch, map[i].freq);
            index += map[i].freq;
        }
    }
    result[index] = '\0';

    return result;
}
