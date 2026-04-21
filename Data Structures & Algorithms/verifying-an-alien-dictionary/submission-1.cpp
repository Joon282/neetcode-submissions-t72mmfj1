class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        for (int j = 0; j < words.size() - 1; j++) {
            string word1 = words[j];
            string word2 = words[j + 1];
            int k = 0;
            while (k < word1.size() && k < word2.size()) {
                if (word1[k] == word2[k]) {
                    k++;
                    continue;
                }
                if (dict[word1[k]] > dict[word2[k]]) {
                    return false;
                } else {
                    break;
                }
            }
            if (k == word2.size() && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};