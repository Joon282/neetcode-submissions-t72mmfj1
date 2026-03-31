class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0; 
        int right = 0;
        while (left < s.length() && right < t.length()){
            if (s[left] == t[right]){
                left++;
            }
            right++;
        }
        if (left == s.length()){
            return true;
        } 
        return false;
    }
};