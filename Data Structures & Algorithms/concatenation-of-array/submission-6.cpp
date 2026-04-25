class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int j = n;
        nums.resize(2 * n);
        for (int i = 0; i < n; i++){    
            nums[j++] = nums[i];      
        }
        return nums;
    }
};