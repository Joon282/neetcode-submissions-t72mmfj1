class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.length()){
            if (s[i] == t[j]){
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (t.length() - j < 0){
            return 0;
        }
        return t.length() - j;
    }
};