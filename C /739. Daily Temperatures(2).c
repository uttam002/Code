/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
   int* result = (int*)malloc(temperaturesSize * sizeof(int));
    *returnSize = temperaturesSize;

    // Stack to store indices of temperatures that have not found a warmer day yet
    int stack[temperaturesSize];
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }

    // Set the remaining indices in result to 0 (no warmer day found)
    for (int i = 0; i <= top; i++) {
        result[stack[i]] = 0;
    }

    return result;
}
