class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty() || s2.empty()){
            return false;
        }
        std::unordered_map<char,int> freq1;
        std::unordered_map<char,int> freq2;
        for (const char& c : s1){
            freq1[c]++;
        }
        int length = s1.length();
        int left = 0;
        for (int right = 0; right < s2.length(); right++){
            freq2[s2[right]]++;
            while (right - left + 1 > length){
                freq2[s2[left]]--;
                if (freq2[s2[left]] == 0){
                    freq2.erase(s2[left]);
                }
                left++;
            }
            if (freq2 == freq1){
                return true;
            }
        }
        return false;
    }
};
