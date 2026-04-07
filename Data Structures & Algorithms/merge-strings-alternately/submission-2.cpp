class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        std::string word = "";
        int min = std::min(word2.length(), word1.length());
        while (i < min){
            word += word1[i];
            word += word2[i];
            i++;
        }
        if (word2.length() > word1.length()){
            word += word2.substr(min);
        }
        if (word1.length() > word2.length()){
            word += word1.substr(min);
        }
        return word;
    }
};