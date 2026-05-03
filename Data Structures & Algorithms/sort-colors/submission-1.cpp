class Solution {
    // 1 0 2 1 0 1
    // 0 1 2 1 0 1
    // 0 1 1 1 0 2
public:
    void sortColors(vector<int>& nums) {
       int i = 0;
       int j = 0;
       int k = nums.size() - 1;
       while (j <= k){
            if (nums[j] == 0){
                std::swap(nums[j], nums[i]);
                i++;
                j++;
            } else if(nums[j] == 2){
                std::swap(nums[j], nums[k]);
                k--;
                j++;
            } else {
                j++;
                continue;
            }
       }
    }
};