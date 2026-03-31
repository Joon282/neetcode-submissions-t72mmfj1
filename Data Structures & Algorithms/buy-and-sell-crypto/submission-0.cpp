class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = prices.size()-1;
        int maxProfit = prices[right] - prices[left];
        while (left < right){
            if (prices[left] > prices[right]){
                left++;
            } else {
                right--;
            }
            int profit = prices[right] - prices[left];
            maxProfit = std::max(maxProfit, profit);
        }
        return maxProfit;
    }
};
