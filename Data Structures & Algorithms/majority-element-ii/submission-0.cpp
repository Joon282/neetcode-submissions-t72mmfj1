class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        std::vector<int> results;
        std::unordered_map<int,int> map1;
        for (int i = 0; i < nums.size(); i++){
            map1[nums[i]]++;
        }
        for (const auto it: map1){
            if (it.second > n){
                results.push_back(it.first);
            }
        }
        return results;
    }
};