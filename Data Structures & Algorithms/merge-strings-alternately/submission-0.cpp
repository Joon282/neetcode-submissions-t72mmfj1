class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        if (word1.length() > word2.length()){
            std::swap(word1, word2);
        }
        std::string word = "";
        while (i < word1.length()){
            word += word1[i];
            word += word2[i];
            i++;
        }
        if (word.length() != word2.length() + word1.length()){
            word += word2.substr(i);
        }
        return word;
    }
};