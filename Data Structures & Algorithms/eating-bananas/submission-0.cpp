class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (h == 0){
            return 0;
        }
        int max = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            if (piles[i] > max){
                max = piles[i];
            } 
        }
        int left = 1; 
        int right = max;
        int result = right;
        while (left <= right){
            int middle = left + (right - left) / 2;
            long long time = 0;
            for (int p : piles){
                time += std::ceil((double)p / middle);
            }
            if (time <= h){
                result = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return result;
    }
};
