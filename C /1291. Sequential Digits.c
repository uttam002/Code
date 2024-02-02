
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int resultSize = high - low + 1;
    int* result = (int*)malloc(resultSize * sizeof(int));
    int index = 0;

    for (int i = 1; i <= 9; i++) {
        int current = i;

        while (current <= high) {
            if (current >= low) {
                result[index++] = current;
            }

            int lastDigit = current % 10;
            if (lastDigit < 9) {
                current = current * 10 + (lastDigit + 1);
            } else {
                break;
            }
        }
    }

    // Sorting the result array using qsort
    qsort(result, index, sizeof(int), compare);

    *returnSize = index;
    return result;
}
