class Solution {
    public int maxProfit(int[] prices) {
         if (prices == null || prices.length <= 1) {
            return 0; // No profit can be made with less than 2 prices
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int currentPrice : prices) {
            minPrice = Math.min(minPrice, currentPrice);
            int currentProfit = currentPrice - minPrice;
            maxProfit = Math.max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
}
