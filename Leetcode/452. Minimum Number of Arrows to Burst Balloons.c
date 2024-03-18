int compare(const void* a, const void* b) {
    const int* arr1 = *(const int**)a;
    const int* arr2 = *(const int**)b;
    long long diff = (long long)arr1[0] - arr2[0]; 
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}


int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);
    int y = points[0][1];
    int ans = 1;
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > y) {
            ans++;
            y = points[i][1];
        }
        y = (points[i][1] < y) ? points[i][1] : y;
    }

    return ans;
}
