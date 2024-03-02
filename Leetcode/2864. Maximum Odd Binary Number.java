class Solution {
    public String maximumOddBinaryNumber(String s) {
        return Arrays.stream(s.split("")).sorted(Comparator.reverseOrder()).skip(1).collect(Collectors.joining()) + "1";
    }
}
