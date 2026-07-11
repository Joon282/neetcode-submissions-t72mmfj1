class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        nums.resize(2*size);
        int j = 0;
        for (int i = size; i < nums.size(); i++){
            nums[i] = nums[j++]; 
        }
        return nums;
    }
};