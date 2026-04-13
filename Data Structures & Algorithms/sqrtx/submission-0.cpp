class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int val = 0;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (mid * mid == x){
                return mid;
            }
            if (mid * mid > x){
                right = mid - 1;
            } else {
                val = mid;
                left = mid + 1;
            }
        }
        return val;
    }
};