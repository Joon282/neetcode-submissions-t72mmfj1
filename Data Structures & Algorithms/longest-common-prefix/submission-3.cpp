class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(), strs.end());
        std::string first = strs[0];
        std::string last = strs[strs.size()-1];
        std::string lcp = "";
        for (int i = 0; i < first.length(); i++){
            if (first[i] == last[i]){
                lcp += first[i];
            } else {
                break;
            }
        }
        return lcp;
    }
};