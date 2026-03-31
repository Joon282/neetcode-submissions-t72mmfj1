class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for (const int& num : nums){
            if (num == 1){
                count++;
            } else {
                count = 0;
            }
            max = std::max(max,count);
        }
        return max;
    }
};