class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        std::unordered_map<int,int> freq;
        for (int num : nums){
            freq[num]++;
        }
        for (const auto& it : freq) {
            int num = it.first;
            int count = it.second;
            if (count > n){
                return num;
            }
        }
        return 0;
    }
};