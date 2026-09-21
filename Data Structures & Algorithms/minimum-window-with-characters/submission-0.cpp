class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }
        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;
        int left = 0;
        int minLength = INT_MAX;
        int startIndex = 0;
        for (const char& c : t){
            freq1[c]++;
        }
        int have = 0;
        int need = freq1.size();
        for (int right = 0; right < s.size(); right++){
            freq2[s[right]]++;
            if (freq1.count(s[right]) && freq2[s[right]] == freq1[s[right]]) {
                have++;
            }
            while (have == need){
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                freq2[s[left]]--;
                if (freq1.count(s[left]) && freq2[s[left]] < freq1[s[left]]){
                    have--;
                }
                left++;
            }
        }
        if (minLength != INT_MAX) {
            return s.substr(startIndex, minLength);
        }
        return "";
    }
};
