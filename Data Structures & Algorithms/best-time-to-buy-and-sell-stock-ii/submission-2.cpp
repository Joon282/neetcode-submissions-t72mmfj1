class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++){
            int profit = 0;
            int j = i + 1;
            int currStock = prices[i];
            int tomStock = prices[j];
            if (currStock >= tomStock){
                continue;
            } else {
                profit = tomStock - currStock;
                maxProfit += profit;
            }
        }
        return maxProfit;
    }
};