class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;
        // [-3,0,1,2,3,3]
        for (int i = 0; i < nums.size()-3; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for (int j = i+1; j < nums.size()-2; j++){
                if (j > 0 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = nums.size()-1;
                int difference = target - nums[i] - nums[j];
                while (k < l){
                    int sum = nums[k] + nums[l];
                    if (sum == difference){
                        results.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k--;
                        l++;
                        while (k < l && (nums[k] == nums[k-1])) {
                            j++;
                        }
                        while (k < l && (nums[l] == nums[l+1])) {
                            k--;
                        }
                    } else if (sum > difference){
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        return results;
    }
};