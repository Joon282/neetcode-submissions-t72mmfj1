class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int num : nums){
            if (num != val){
                nums[j++] = num;
            } else {
                continue;
            }
        }
        return j;
    }
};