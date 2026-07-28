class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right){
            if (!std::isalnum(s[left])){
                left++;
                continue;
            } else if (!std::isalnum(s[right])){
                right--;
                continue;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])){
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};
