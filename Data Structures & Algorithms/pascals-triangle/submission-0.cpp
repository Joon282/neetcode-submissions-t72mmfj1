class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> results;
        for (int i = 0; i < numRows; i++){
            std::vector<int> rows;
            int value = 1;
            for (int k = 0; k <= i; k++){
                rows.push_back(value);
                value = value * (i - k) / (k + 1);
            }
            results.push_back(rows);
        }
        return results;
    }
};