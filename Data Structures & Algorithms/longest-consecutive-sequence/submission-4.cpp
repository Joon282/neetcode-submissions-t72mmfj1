class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        std::unordered_set<int> numSet(nums.begin(),nums.end());
        //4 2 10 5 3 20
        int max = 0;
        for (const auto it : numSet){
            if (!numSet.count(it - 1)) {
                int start = it;
                int freq = 1;
                while (numSet.count(start + 1)){
                    start++;
                    freq++;
                    max = std::max(freq,max);
                }
            }
        }
        return max;
    }
};
