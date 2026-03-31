class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::string temp = "";
        int maxLength = 0;
        for (const char& c : s){
            while (temp.find(c) != std::string::npos){
                temp.erase(0,1);
            }
            temp += c;
            maxLength = std::max(static_cast<int>(temp.length()), maxLength);
        }
        return maxLength;
    }
};
