class Solution {
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
        }
    }
}
