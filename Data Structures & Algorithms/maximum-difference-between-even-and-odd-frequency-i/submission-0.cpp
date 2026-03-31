class Solution {
public:
    int maxDifference(string s) {
        std::unordered_map<char, int> freqCount;
        int maxOdd = 0;
        int maxEven = 0;
        for (const char& c : s) {
            freqCount[c]++;
        }
        for (const auto& it : freqCount){
            char letter = it.first;
            int count = it.second;
            if (count % 2 == 0){
                maxEven = std::max(count, maxEven);
            } else {
                maxOdd = std::max(count, maxOdd);
            }
        }
        return maxOdd - maxEven;
    }
};