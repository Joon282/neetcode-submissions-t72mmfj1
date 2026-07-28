class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> table(nums.begin(), nums.end());
        int value = 1;
        for (int i = 0; i < nums.size(); i++){
            if (table.contains(value)){
                value++;
            } else {
                return value;
            }
        }
        return -1;
    }
};