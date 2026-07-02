class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();;
        while (k > 0){
            int last = nums[nums.size()-1];
            int prev = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                int temp = nums[i];
                nums[i] = prev;
                prev = temp;
            }
            nums[0] = last;
            k--;
        }
    }
};