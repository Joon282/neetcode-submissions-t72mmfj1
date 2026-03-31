class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()){
            while (i > 0 && nums[i] == nums[i-1]){
                i++;
            }
            int difference = -nums[i];
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k){
                int sum = nums[j] + nums[k];
                if (sum == difference){
                    while (j < k && (nums[j] == nums[j+1])) {
                        j++;
                    }
                    while (j < k && (nums[k] == nums[k-1])) {
                        k--;
                    }
                    results.push_back({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                } else if (sum > difference){
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        return results;
    }
};
