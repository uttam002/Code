#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize) {
    long long result = 0;
    int left[arrSize], right[arrSize];

    for (int i = 0, j; i < arrSize; left[i++] = j)
        for (j = i - 1; j >= 0 && arr[i] < arr[j]; j = left[j]);

    for (int i = arrSize - 1, j; i >= 0; right[i--] = j)
        for (j = i + 1; j < arrSize && arr[i] <= arr[j]; j = right[j]);

    for (int i = 0; i < arrSize; result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i++)) % MOD);

    return (int)result;
}
