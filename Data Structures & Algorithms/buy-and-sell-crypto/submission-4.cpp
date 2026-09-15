class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int left = 0;
        int right = 1;
        while (right < prices.size()){
            if (prices[right] > prices[left]){
                int profit = prices[right] - prices[left];
                max = std::max(profit,max);
            } else {
                left = right;
            }
            right++;
        }
        
    }
    return max;
};
