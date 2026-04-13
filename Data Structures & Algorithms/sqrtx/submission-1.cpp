class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int val = 0;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid == x){
                return mid;
            }
            if ((long long) mid * mid < x){
                val = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return val;
    }
};