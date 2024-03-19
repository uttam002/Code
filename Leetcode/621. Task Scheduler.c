int leastInterval(char* tasks, int tasksSize, int n) {
    #define MAX_TASKS 26     
    int taskCounts[MAX_TASKS] = {0};
    int maxFrequency = 0,maxCount = 0;
    for (int i = 0; i < tasksSize; i++) taskCounts[tasks[i] - 'A']++;
    for (int i = 0; i < MAX_TASKS; i++) if (taskCounts[i] > maxFrequency)maxFrequency = taskCounts[i];

    for (int i = 0; i < MAX_TASKS; i++) if (taskCounts[i] == maxFrequency)maxCount++;
    int result = (maxFrequency - 1) * (n + 1) + maxCount;
    return result > tasksSize ? result : tasksSize;
}
