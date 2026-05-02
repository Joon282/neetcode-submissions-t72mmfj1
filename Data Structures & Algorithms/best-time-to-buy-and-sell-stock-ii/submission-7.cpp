class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int j = 1;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] >= prices[j]){
                j++;
                continue;
            } else {
                int profit = prices[j] - prices[i];
                max += profit;
            }
            j++;
        }   
        return max;
    }
};