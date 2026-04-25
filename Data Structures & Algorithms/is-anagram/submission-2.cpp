class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> freq2;
        for (char c : s){
            freq[c]++;
        }
        for (char c : t){
            freq[c]++;
        }
        return freq == freq2;
    }
};
