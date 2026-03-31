class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> map1;
        int length = s.length();
        int i = 0;
        std::string temp = s;
        while (i < length){
            map1[s[i]] = t[i];
            i++;
        }
        for (const auto it: map1){
            if (map1.count(it.second) > 1){
                return false;
            }
        }
        for (int i = 0; i < length; i++){
            if (map1.find(temp[i]) != map1.end()){
                temp[i] = map1[temp[i]];
            }
        }
        return temp == t;
    }
};