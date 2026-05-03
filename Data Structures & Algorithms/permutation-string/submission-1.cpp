class Solution {
    /*
    Goal: Check if s1 is a permuation of a substring in s2

    Approach (sliding window + hashmap):
    1. Form a sliding window with size r-l+1on s2
    2. In each window store the count of char freq
    3. Compare the window map to s1 map
    4. if equal return true
    5. While window size > s1 length decrement or erase s[left] and increase left
    6. Keep expanding to the right
    */
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty() || s2.empty()){
            return false;
        }
        std::unordered_map<char, int> s1Freq;
        std::unordered_map<char, int> s2Freq;
        for (const char c : s1){
            s1Freq[c]++;
        }
        int m = s1.length();
        int n = s2.length();
        if (n < m){
            return false;
        }
        int left = 0;
        for (int right = 0; right < n; right++){
            s2Freq[s2[right]]++;
            if (right - left + 1 > m){
                s2Freq[s2[left]]--;
                if (s2Freq[s2[left]] == 0){
                    s2Freq.erase(s2[left]);
                }
                left++;
            }
            if (s1Freq == s2Freq){
                return true;
            }
        }
        return false;
    }
};
