class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minmal=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int cost=prices[i]-minmal;
            profit=max(profit,cost);
            minmal=min(minmal,prices[i]);
        }
        return profit;
    }
};
