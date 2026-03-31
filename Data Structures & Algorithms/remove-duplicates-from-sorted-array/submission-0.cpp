class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;
        int j = i + 1;

        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == nums[j - 1]) {
                j++;
            }
            if (j < nums.size()) {   
                nums[++i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};
