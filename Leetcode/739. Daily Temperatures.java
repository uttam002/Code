class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
      int temperaturesSize = temperatures.length;
        int[] result = new int[temperaturesSize];

        for (int i = 0; i < temperaturesSize; ++i)
            result[i] = 0;

        for (int i = temperaturesSize - 1; i >= 0; --i) {
            int j = i + 1;

            while (j < temperaturesSize && temperatures[j] <= temperatures[i]) {
                if (result[j] <= 0)
                    break;
                j += result[j];
            }

            if (j < temperaturesSize && temperatures[j] > temperatures[i]) {
                result[i] = j - i;
            }
        }

        return result;
    }  
}
