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
            int size = min(word1.size(), word2.size());
            bool foundDifference = false;
            for (int k = 0; k < size; k++) {
                if (word1[k] != word2[k]) {
                    if (dict[word1[k]] > dict[word2[k]]) {
                        return false;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};