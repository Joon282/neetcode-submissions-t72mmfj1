class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max = 0;
        while (left < right){
            int length = right - left;
            int height = std::min(heights[left], heights[right]);
            int area = length * height;
            max = std::max(area,max);
            if (heights[left] > heights[right]){
                right--;
            } else {
                left++;
            }
        }
        return max;
    }
};
