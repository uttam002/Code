Interval* insertInterval(Interval* intervals, int intervalsSize, Interval newInterval,
                         int* returnSize) {
    Interval* result = malloc((intervalsSize + 1) * sizeof(Interval));
    *returnSize = 0;
    int i = 0;

    // Add intervals before the newInterval
    while (i < intervalsSize && intervals[i].end < newInterval.start) {
        result[(*returnSize)++] = intervals[i++];
    }

    // Merge overlapping intervals with the newInterval
    while (i < intervalsSize && intervals[i].start <= newInterval.end) {
        newInterval.start = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start;
        newInterval.end = (intervals[i].end > newInterval.end) ? intervals[i].end : newInterval.end;
        i++;
    }

    // Add the merged interval
    result[(*returnSize)++] = newInterval;

    // Add remaining intervals
    while (i < intervalsSize) {
        result[(*returnSize)++] = intervals[i++];
    }

    return result;
}
