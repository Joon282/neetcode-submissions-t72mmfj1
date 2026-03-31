class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::unordered_set<std::string> sort;
        std::vector<std::string> result;
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < words.size(); j++){
                if (i == j){
                    continue;
                }
                if (words[i].find(words[j]) != string::npos){
                    sort.insert(words[j]);
                }
            }
        }
        for (const auto item : sort){
            result.push_back(item);
        }
        return result;
    }
};