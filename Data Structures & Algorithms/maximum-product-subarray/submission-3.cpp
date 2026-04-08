class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> maxDP(n + 1, 0);
        std::vector<int> minDP(n + 1, 0);
        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < n; i++){
            maxDP[i] = std::max({nums[i], maxDP[i-1] * nums[i], minDP[i-1] * nums[i]});
            minDP[i] = std::max({nums[i], maxDP[i-1] * nums[i], minDP[i-1] * nums[i]});
            max = std::max(max, maxDP[i]);
        }
        return max;
    }
};
