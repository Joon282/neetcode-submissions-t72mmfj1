class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> results;
        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        for (const std::string& str : strs){
            std::vector<int> arrays(26,0);
            for (const char c : str){
                arrays[c - 'a']++;
            }
            std::string temp = "";
            for (int i = 0; i < 26; i++){
                temp += std::to_string(arrays[i]) + '#';
            }
            hashMap[temp].push_back(str);
        }
        for (const auto& it : hashMap){
            results.push_back(it.second);
        }
        return results;
    }
};
