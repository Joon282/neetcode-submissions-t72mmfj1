class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;
        for (const char c : s){
            freq1[c]++;
        }
        for (const char c : s){
            freq2[c]++;
        }
        return freq2 == freq1;
    }
};
