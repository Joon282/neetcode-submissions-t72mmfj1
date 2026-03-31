class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> res;
        for (int i = 0; i < arr.size() - 1; i++){
            int max = 0;
            for (int j = i + 1; j < arr.size(); j++){
                max = std::max(max, arr[j]);
            }
            res.push_back(max);
        }
        res.push_back(-1);
        return res;
    }
};