class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++){
            freq[s[i]]++;
            int count = std::max(count, freq[s[i]]);
            if (i - start + 1 - count > k){
                freq[s[start]]--;
                start++;
            }
            maxLength = std::max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};
