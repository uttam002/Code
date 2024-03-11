import java.util.*;

public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Sort both input arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // Initialize variables
        int prev = -1;  // To track the previous common element
        int i = 0;      // Pointer for nums1 array
        int j = 0;      // Pointer for nums2 array

        // List to store intersection elements
        ArrayList<Integer> resultList = new ArrayList<>();

        // Iterate over both arrays to find common elements
        while (i < nums1.length && j < nums2.length) {
            int first = nums1[i];   // Current element in nums1
            int second = nums2[j];  // Current element in nums2

            // If both elements are equal and not equal to previous common element
            if (first == second && prev != first) {
                resultList.add(first);  // Add common element to the result list
                prev = first;           // Update previous common element
                i++;                    // Move to the next element in nums1
                j++;                    // Move to the next element in nums2
            } else if (first < second) {
                i++;  // Move to the next element in nums1
            } else {
                j++;  // Move to the next element in nums2
            }
        }

        // Convert the ArrayList to an array and return
        return resultList.stream().mapToInt(Integer::intValue).toArray();
        
    }
}
