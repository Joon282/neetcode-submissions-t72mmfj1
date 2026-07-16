class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> results;
        std::unordered_map<int, int> freq;
        for (const int num : nums){
            freq[num]++; //stores each number in the freq map with a corresponding count
        }
        std::priority_queue<std::pair<int,int>> pq;
        for (const auto& it : freq){
            int count = it.second;
            int num = it.first;
            pq.push({count, num});
        }
        while (k > 0){
            results.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return results;
    }
};
