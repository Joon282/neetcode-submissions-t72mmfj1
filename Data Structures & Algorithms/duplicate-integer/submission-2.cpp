class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++){
            
            if (map1.find(nums[i]) != map1.end()) {
                return true;
            }
            map1[nums[i]] = i;
        }
        return false;
    }
};