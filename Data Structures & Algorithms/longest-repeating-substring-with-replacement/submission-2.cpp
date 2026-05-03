class Solution {
    // k number of replacements within string s
    // All chars in s are uppercase
    /*
        Goal: Find the longest substring in s with only 1 unique char with at most k replacements

        Approach using hashmap & Sliding window:
        1. Form a window of length r - l + 1
        2. Count the freq of each char in the window
        3. Calculate Window Size - maxfreq
        4. while the Window Size - maxfreq > k erase s[left]-- and increase left
        5. Otherwise continue expanding right
        
    */
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        std::unordered_map<char, int> count;
        int maxLen = 0;
        int maxFreq = 0;
        for (int right = 0; right < s.length(); right++){
            count[s[right]]++;
            maxFreq = std::max(maxFreq, count[s[right]]);
            if ((right - left + 1) - maxFreq > k){
                count[s[left]]--;
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
