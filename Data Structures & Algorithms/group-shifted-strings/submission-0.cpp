class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::vector<std::vector<std::string>> results;
        std::unordered_map<std::string, std::vector<std::string>> map1;
        for (const std::string& str : strings){
            std::string key = "";
            int previous = str[0] - 'a';
            for (char c : str){
                int current = c - 'a';
                int difference = (current - previous + 26) % 26;
                key += std::to_string(difference) + '#';
            }
            map1[key].push_back(str);
        }
        for (const auto it : map1){
            results.push_back(it.second);
        }
        return results;
    }
};
