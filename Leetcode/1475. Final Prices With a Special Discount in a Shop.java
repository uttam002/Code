class Solution {
    public int[] finalPrices(int[] prices) {
      return java.util.stream.IntStream.range(0, prices.length)
                .map(i -> prices[i] - java.util.stream.IntStream.range(i + 1, prices.length)
                        .filter(j -> prices[j] <= prices[i])
                        .map(j -> prices[j])
                        .findFirst().orElse(0))
                .toArray();
   
    }
}
