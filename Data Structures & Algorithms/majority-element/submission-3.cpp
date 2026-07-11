class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
            if (freq[num] > nums.size()/2){
                return num;
            }
        }
        return 0;
    }
};