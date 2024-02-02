/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void generateSequentialDigits(int low, int high, int current, int* result, int* index) {
    if (current > high) {
        return;
    }

    if (current >= low) {
        result[(*index)++] = current;
    }

    int lastDigit = current % 10;
    if (lastDigit < 9) {
        generateSequentialDigits(low, high, current * 10 + (lastDigit + 1), result, index);
    }
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int resultSize = high - low + 1;
    int* result = (int*)malloc(resultSize * sizeof(int));
    int index = 0;

    for (int i = 1; i <= 9; i++) {
        generateSequentialDigits(low, high, i, result, &index);
    }
    *returnSize = index;
    qsort(result, index, sizeof(int), compare);
    return result;
}
