class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
        std::unordered_map<int,int> numCount;

        for (const int& num : nums){
            numCount[num]++;
        } // {[3,2],[2,2],[1,1]}
         std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (const auto& it : numCount){
            int number = it.first;
            int count = it.second;
            pq.push({count, number});
            if (pq.size() > k){
                pq.pop();
            }
        }
        while (pq.size() > 0){
            int value = pq.top().second;
            result.push_back(value);
            pq.pop();
        }
        return result;
    }
};
