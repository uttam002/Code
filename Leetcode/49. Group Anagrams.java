class Solution {
    // public static boolean areAnagrams(String str1, String str2) {
    //     // Check if lengths are different, if so, they can't be anagrams
    //     if (str1.length() != str2.length()) {
    //         return false;
    //     }

    //     // Initialize an array to store the frequency of each character
    //     int[] charFrequency = new int[256]; // Assuming ASCII characters

    //     // Count the frequency of characters in the first string
    //     for (char ch : str1.toCharArray()) {
    //         charFrequency[ch]++;
    //     }

    //     // Subtract the frequency of characters in the second string
    //     for (char ch : str2.toCharArray()) {
    //         charFrequency[ch]--;
    //     }

    //     // If all entries in the charFrequency array are 0, the strings are anagrams
    //     for (int frequency : charFrequency) {
    //         if (frequency != 0) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }
    // Helper method to create a list of String
    // private static List<String> createIntegerList(String elements) {
    //     List<String> innerList = new ArrayList<>();
    //     for (String element : elements) {
    //         innerList.add(element);
    //     }
    //     return innerList;
    // }
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashMap = new HashMap<>();

        for (String str : strs) {
            // Sort the characters of the current string
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);

            // If the sorted string is already in the map, add the current string to its corresponding list
            // Otherwise, create a new list and add the current string to it
            if (hashMap.containsKey(sortedStr)) {
                hashMap.get(sortedStr).add(str);
            } else {
                List<String> newList = new ArrayList<>();
                newList.add(str);
                hashMap.put(sortedStr, newList);
            }
        }
        
        
        return new ArrayList<>(hashMap.values());

        // int count=0;
       
        //     for (String element : strs) {
        //     innerList.add(element);
        // }
        
    }
}
