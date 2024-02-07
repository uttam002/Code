class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }
         // Sort the characters based on their frequencies
        List<Character> characters = new ArrayList<>(freqMap.keySet());
        Collections.sort(characters, (a, b) -> freqMap.get(b) - freqMap.get(a));
       
        // // Create a priority queue to sort characters by frequency
        // PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> freqMap.get(b) - freqMap.get(a));
        // pq.addAll(freqMap.keySet());
        
       StringBuilder result = new StringBuilder();
        for (char c : characters) {
            int freq = freqMap.get(c);
            for (int i = 0; i < freq; i++) {
                result.append(c);
            }
        }
        
        return result.toString();
    }
}
