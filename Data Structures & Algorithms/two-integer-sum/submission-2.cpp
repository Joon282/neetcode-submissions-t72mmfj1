class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> result;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (result.contain(difference)) {
                return {result[difference], i};
            }
            result[nums[i]] = i;
        }
    }
};
