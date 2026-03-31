class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        std::vector<std::string> res;
        for (int i = 0; i < words.size(); i++) {
            std::string result = "";
            for (const std::string& word : words) {
                if (i >= word.length()){
                    break;
                }
                result += word[i];
            }
            res.push_back(result);
        }
        return (words == res);
    }
};
