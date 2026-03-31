class Solution {
public:
    int lengthOfLastWord(string s) {
        std::string word = "";
        std::string lastWord = "";
        for (int i = 0; i < s.length(); i++){
            if (!std::isspace(s[i])){
                word += s[i];
                lastWord = word;
            } else {
                word = "";
            }
        }
        return lastWord.length();
    }
};