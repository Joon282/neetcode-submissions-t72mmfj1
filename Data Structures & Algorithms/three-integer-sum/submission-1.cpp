class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()){
            return {};
        }
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> results;
        for (int i = 0; i < nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            int sum = nums[j] + nums[k];
            int diff = -nums[i];
            while (j < k){
                if (sum == diff) {
                    while (j < k && nums[j] == nums[j+1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum > diff){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return results;
    }
};
