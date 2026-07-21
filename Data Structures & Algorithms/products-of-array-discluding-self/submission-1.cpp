class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = nums.size();
        std::vector<int> results(m);
        std::vector<int> prefix(m);
        std::vector<int> suffix(m);
        prefix[0] = nums[0];
        suffix[m-1] = nums[m-1];

        for (int i = 1; i < m; i++){
            prefix[i] = prefix[i-1] * nums[i]; 
        }

        for (int i = m - 2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        results[0] = suffix[1];  
        results[m-1] = prefix[m-2];

        for (int i = 1; i < m - 1; i++){
            results[i] = prefix[i-1] * suffix[i+1];
        }
        return results;
    }
};