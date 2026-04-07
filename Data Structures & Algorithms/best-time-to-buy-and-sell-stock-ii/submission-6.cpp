class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++){
            int j = i + 1;
            if (prices[i] >= prices[j]){
                continue;
            } else {
                int profit = prices[j] - prices[i];
                maxProfit += profit;
            }
        }
        return maxProfit;
    }
};