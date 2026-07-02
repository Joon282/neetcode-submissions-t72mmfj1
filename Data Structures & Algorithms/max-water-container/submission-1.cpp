class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right){
            int area = (right - left) * std::min(heights[left], heights[right]);
            maxArea = std::max(area, maxArea);
            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
