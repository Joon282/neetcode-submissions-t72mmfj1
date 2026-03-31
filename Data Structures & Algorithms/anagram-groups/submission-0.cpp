class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> results;
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (std::string str : strs){
            std::vector<int> array(26, 0);
            for (char c : str){
                array[c - 'a']++;
            }
            string s = "";
            for (int i = 0; i < 26; i++){
                s += std::to_string(array[i]) + '#';
            }
            map[s].push_back(str);
        }
        for (const auto& it : map){
            results.push_back(it.second);
        }
        return results;
    }
};
