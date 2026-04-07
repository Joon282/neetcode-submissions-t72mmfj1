class Solution {
public:
    int dP(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1){
            return nums[start];
        }
        std::vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start+1]);
        for (int i = 2; i < n; i++){
            dp[i] = std::max(nums[start + i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
     int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        return std::max(dP(nums, 0, n-2), dP(nums, 1, n-1));
    }
};
