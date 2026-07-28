class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int left = 0;
        int right = 1;
        while (right < prices.size()){
            if (prices[left] >= prices[right]){
                left++;
                right++;
            } else {
                int profit = prices[right] - prices[left];
                max += profit;
                right++;
                left++;
            }
        }
        return max;
    }
};