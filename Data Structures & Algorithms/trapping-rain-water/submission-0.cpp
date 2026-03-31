class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int rightMax = height[right];
        int leftMax = height[left];
        int maxArea = 0;
        while (left < right){
            if (leftMax < rightMax){
                left++;
                leftMax = std::max(leftMax, height[left]);
                maxArea += leftMax - height[left];
            } else {
                right--;
                rightMax = std::max(rightMax, height[right]);
                maxArea += rightMax - height[right];
            }
        }
        return maxArea
    }
};
