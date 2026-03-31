class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int maxArea = 0;
        int right = heights.size() - 1;
        while (left < right){
            int height = std::min(heights[left], heights[right]);
            int length = right - left;
            int area = height * length;
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
