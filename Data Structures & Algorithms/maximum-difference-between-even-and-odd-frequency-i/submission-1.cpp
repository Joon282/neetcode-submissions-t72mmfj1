class Solution {
public:
    int maxDifference(string s) {
        std::unordered_map<char, int> freqCount;
        int maxOdd = 0;
        int minEven = INT_MAX;
        for (const char& c : s) {
            freqCount[c]++;
        }
        for (const auto& it : freqCount){
            char letter = it.first;
            int count = it.second;
            if (count % 2 == 0){
                minEven = std::min(count, minEven);
            } else {
                maxOdd = std::max(count, maxOdd);
            }
        }
        return maxOdd - minEven;
    }
};