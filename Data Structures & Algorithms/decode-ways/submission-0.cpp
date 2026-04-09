class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        if (s[0] != '0'){
            dp[1] = 1;
        } else {
            dp[1] = 0;
        }
        for (int i = 2; i <= s.length(); i++){
            if (s[i] != '0'){
                dp[i] += dp[i-1];
            }
            int digits = std::stoi(s.substr(i-2, 2));
            if (digits >= 10 && digits <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }
};
