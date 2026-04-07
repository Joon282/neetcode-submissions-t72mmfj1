class Solution {
public:
    int countSubstrings(string s) {
        std::string longest = "";
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            int left = i;
            int right = i;
            while (left >= 0 && right < s.length()){
                if (s[left] == s[right]){
                    if (right - left + 1 > longest.length()){
                        longest = s.substr(left, right - left + 1);
                        count++;
                    }
                    left--;
                    right++;
                } else {
                    break;
                }
            }

            left = i;
            right = i+1;
            while (left >= 0 && right < s.length()){
                if (s[left] == s[right]){
                    if (right - left + 1 > longest.length()){
                        longest = s.substr(left, right - left + 1);
                        count++;
                    }
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};