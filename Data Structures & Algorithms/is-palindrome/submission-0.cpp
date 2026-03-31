class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        std::string temp = "";
        for (const char& c : s){
            if (!std::alnum(c)){
                continue;
            }
            temp += c;
        }
        while (i < j){
            if (temp[i] == temp[j]){
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};
