#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int maxProfit(int* prices, int pricesSize) {
    int minVal = INT_MAX;
    int result = 0;
    
    for(int i = 0 ; i < pricesSize ; i++ )
    {
        minVal = min(minVal, prices[i]);
        result = max(result, prices[i] - minVal);
    }
    return result;
}
