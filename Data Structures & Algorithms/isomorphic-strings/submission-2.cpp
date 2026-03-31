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
        std::unordered_set<char> seen;
        for (const auto& it : map1) {
            if (seen.count(it.second)) {
                return false;
            }
            seen.insert(it.second);
        }
        for (int i = 0; i < length; i++){
            if (map1.find(temp[i]) != map1.end()){
                temp[i] = map1[temp[i]];
            }
        }
        return temp == t;
    }
};