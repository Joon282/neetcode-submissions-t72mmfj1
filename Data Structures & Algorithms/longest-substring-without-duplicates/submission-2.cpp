class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::string temp = "";
        int max = 0;
        int left = 0;
        for (const char& c : s) {
            while (temp.find(c) != std::string::npos){
                temp.erase(0,1);
            }
            temp += c;
            max = std::max(static_cast<int>(temp.length()), max);
        }
        return max;
    }
};
