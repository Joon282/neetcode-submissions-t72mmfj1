class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalindrome(s)){
            return true;
        }
        for (int i = 0; i < s.length(); i++){
            std::string temp = s.substr(0,i) + s.substr(i+1);
            if (isPalindrome(temp)){
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right){
            if (!std::isalnum(s[left])){
                left++;
                continue;
            } else if (!std::isalnum(s[right])){
                right--;
                continue;
            }
            if (std::tolower(s[left]) == std::tolower(s[right])){
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};