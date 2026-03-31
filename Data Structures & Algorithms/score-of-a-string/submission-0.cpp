class Solution {
public:
    int scoreOfString(string s) {
        int i = 0;
        int sum = 0;
        while (i < s.length() - 1){
            int difference = std::abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
            sum += difference;
            i++;
        }
        return sum;
    }
};