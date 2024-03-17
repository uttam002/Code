#include <stdbool.h>
#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));
    *returnSize = 0;
    int i = 0;

    // Insert intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        ans[*returnSize] = intervals[i];
        (*returnColumnSizes)[(*returnSize)++] = intervalsColSize[i++];
    }

    // Merge overlapping intervals with newInterval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = (intervals[i][0] < newInterval[0]) ? intervals[i][0] : newInterval[0];
        newInterval[1] = (intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1];
        i++;
    }

    // Insert merged interval
    ans[*returnSize] = newInterval;
    (*returnColumnSizes)[(*returnSize)++] = newIntervalSize;

    // Insert remaining intervals
    while (i < intervalsSize) {
        ans[*returnSize] = intervals[i];
        (*returnColumnSizes)[(*returnSize)++] = intervalsColSize[i++];
    }

    return ans;
}
