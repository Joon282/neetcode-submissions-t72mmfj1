class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //[1,2,3,4,5,6,7,8]
        //[8,1,2,3,4,5,6,7]
        int m = k % nums.size();
        for (int i = 0; i < m; i++){
            int j = nums.size() - 2;
            int k = nums.size() - 1;
            while (j >= 0){
                std::swap(nums[j--], nums[k--]);
            }
        }
    }
};