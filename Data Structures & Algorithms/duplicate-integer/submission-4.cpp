class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> val;
        for (const int num : nums){
            if (val.contains(num)){
                return true;
            }
            val.insert(num);
        }
        return false;
    }
};