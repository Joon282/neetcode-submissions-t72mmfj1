class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> count;
        int result = 0;
        int max = 0;
        for (const int num : nums){
            count.insert(num);
        }
        for (int i = 0; i < nums.size(); i++){
            int value = nums[i];
            int current = 1;
            while (count.contains(value+1)){
                value++;
                current++;
            }
            max = std::max(max, current);
        }
        return max;
    }
};
