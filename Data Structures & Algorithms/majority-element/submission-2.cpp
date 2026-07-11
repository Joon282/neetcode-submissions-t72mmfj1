class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums){
            if (freq[num] >= nums.size()/2){
                return num;
            }
            freq[num]++;
        }
        return 0;
    }
};