class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return {};
        }
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> results;
        std::vector<int> merged = intervals[0];
        for (int row = 0; row < intervals.size()-1; row++){
            int endTime = merged[1];
            int startTime = intervals[row + 1][0];
            if (startTime <= endTime){
                merged = {merged[0], std::max(merged[1], intervals[row + 1][1])};
            } else {
                results.push_back(merged);
                merged = intervals[row + 1];
            }
        }
        results.push_back(merged);
        return results;
    }
};
