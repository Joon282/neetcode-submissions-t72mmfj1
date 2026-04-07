class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map1;
        for (int num : nums){
            map1[num]++;
            if (map1[num] >= 2){
                return num;
            }
        }
        return 0;
    }
};
