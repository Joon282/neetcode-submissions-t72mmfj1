class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> results;
        std::unordered_map<std::string, std::vector<std::string>> hash;
        for (int i = 0; i < strs.size(); i++){
            std::string word = strs[i];
            std::vector<int> vec (26,0);
            for (const char c : word){
                vec[c-'a']++; 
            }
            std::string val = "";
            for (int i = 0; i < 26; i++){
                val += std::to_string(vec[i]) + '#';
            }
            hash[val].push_back(word);
        }
        for (const auto& it : hash){
            results.push_back(it.second);
        }
        return results;
    }
};
