class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> map1;
        for (std::string str : strs){
            std::vector<int> myArray(26,0);
            for (char c : str){
                myArray[c - 'a']++;
            }
            std::string s = "";
            for (int i = 0; i < 26; i++){
                s += std::to_string(myArray[i]) + '#';
            }
            map1[s].push_back(str);
        }
        for (const auto& it : map1){
            result.push_back(it.second);
        }
        return result;
    }
};
