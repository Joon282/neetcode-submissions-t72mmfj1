class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        int max = INT_MIN;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max = std::max(max, dp[i]);
        }
        return max;
    }
};
