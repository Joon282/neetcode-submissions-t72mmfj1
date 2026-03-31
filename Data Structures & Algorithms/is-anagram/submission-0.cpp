class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<int,int> map1;
        std::unordered_map<int,int> map2;
        for (char c : s){
            map1[c]++;
        }
        for (char c : t){
            map2[c]++;
        }
        if (map1 == map2){
            return true;
        }
        return false;
    }
};
