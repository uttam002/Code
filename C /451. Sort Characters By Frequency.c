struct Map{
    int freq;
    char ch;
};
void swap(struct Map *a, struct Map *b) {
    struct Map temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quicksort
int partition(struct Map arr[], int low, int high) {
    int pivot = arr[high].freq;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].freq > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function to sort characters by frequency
void quickSort(struct Map arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


char* frequencySort(char* s) {
    int n = strlen(s);
    struct Map map[256] = {0}; // Increase size to cover entire ASCII range

    // Calculate frequency of each character
    for (int i = 0; i < n; i++) {
        map[(int)s[i]].ch = s[i];
        map[(int)s[i]].freq++;
    }

    // Sort characters by frequency using Quicksort
    quickSort(map, 0, 255); // Increase upper bound to 255

    // Create a new string with characters sorted by frequency
    char *result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < 256; i++) { // Iterate up to 256
        if (map[i].freq > 0) {
            for (int j = 0; j < map[i].freq; j++) {
                result[index++] = map[i].ch;
            }
        }
    }
    result[index] = '\0';

    return result;
}
