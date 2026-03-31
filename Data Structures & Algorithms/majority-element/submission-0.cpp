class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> hash;
        int majority = nums.size()/2;
        for (int num : nums){
            hash[num]++; 
            if (hash[num] > majority){
                return num;
            }
        }
        return 0;
    }
};