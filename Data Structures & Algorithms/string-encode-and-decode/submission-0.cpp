class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedString = "";
        for (std::string str : strs){
            encodedString += std::to_string(str.length()) + '#' + str;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        int i = 0;
        while (i < s.length()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int length = std::stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, length));
            i = j + 1 + length;

        }
        return result;
    }
};
