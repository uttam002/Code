int maxArea(int* height, int heightSize) {
     int maxArea = 0;
    int left = 0, right = heightSize - 1;

    while (left < right) {
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = minHeight * width;
        maxArea = area > maxArea ? area : maxArea;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}
