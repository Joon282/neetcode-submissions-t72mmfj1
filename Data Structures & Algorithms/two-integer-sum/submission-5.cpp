class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (size_t i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if (hash.contains(difference)){
                int min = std::min(hash[difference], static_cast<int>(i));
                int max = std::max(hash[difference], static_cast<int>(i));
                return {min, max};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
