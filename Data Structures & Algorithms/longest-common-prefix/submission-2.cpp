class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(), strs.end());
        std::string longest = strs[strs.size()-1];
        std::string shortest = strs[0];
        std::string prefix = "";
        for (int i = 0; i < shortest.length(); i++){
            if (shortest[i] == longest[i]){
                prefix += shortest[i];
            } else {
                break;
            }
        }
        return prefix;
    }
};