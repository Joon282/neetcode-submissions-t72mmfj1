class Solution {
public:

    string encode(vector<string>& strs) {
        std::string value = "";
        for (const std::string& str : strs){
            int length = str.length();
            value += std::to_string(length) + '#' + str;
        }
        return value;
    }

    vector<string> decode(string s) {
        if (s.length() == 0) {
            return {};
        }
        std::vector<std::string> results;
        int i = 0;
        while (i < s.length()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int length = std::stoi(s.substr(i,j-i));
            results.push_back(s.substr(j+1, length));
            i = j + 1 + length;
        }
        return results;
    }
};
