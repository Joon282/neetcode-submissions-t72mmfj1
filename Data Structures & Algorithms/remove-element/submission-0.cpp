class Solution {
    //Rebuild the nums array with every value excluding VAL
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};