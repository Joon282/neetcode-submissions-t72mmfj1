class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int maxLength = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++){
            while (seen.count(s[i])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            maxLength = std::max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};
