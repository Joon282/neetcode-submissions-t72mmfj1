class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(), strs.end());
        std::string first = strs[0];
        std::string last = strs[strs.size() - 1];
        int i = 0;
        std::string prefix = "";
        while (i < first.length()){
            if (first[i] == last[i]){
                prefix += first[i];
            } else {
                break;
            }
            i++;
        }
        return prefix;
    }
};