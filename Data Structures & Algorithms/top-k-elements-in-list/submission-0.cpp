class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map; //Store the number and its count
        for (const auto& num : nums){
            map[num]++;
        }
        std::priority_queue<std::pair<int,int>> pq; //Initialise a Max-heap for storing pairs of count , number
        for (const auto& pair : map){
            int count = pair.second;
            int number = pair.first;
            pq.push({count, number});
        }
        std::vector<int> results;
        for (int i = 0; i < k; i++) {
            auto it = pq.top();
            results.push_back(it.second);
            pq.pop();
        }   
        return results;
    }
};
