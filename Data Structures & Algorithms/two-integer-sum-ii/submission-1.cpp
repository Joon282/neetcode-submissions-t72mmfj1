class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; int right = numbers.size() - 1;
        while (left < right){
            int sum = numbers[left] + numbers[right];
            int difference = target - sum;
            if (difference == 0){
                return {left + 1, right + 1};
            }
            if (difference < 0){
                right--;
            } else {
                left++;
            }
        }
        return {};
    }
};
