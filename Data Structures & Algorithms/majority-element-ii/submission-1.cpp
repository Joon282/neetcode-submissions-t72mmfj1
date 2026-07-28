class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> results;
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        for (const auto it : freq){
            if (it.second > n/3){
                results.push_back(it.first);
            }
        }
        return results;
    }
};