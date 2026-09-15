class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        for (int i = 0; i < matrix.size(); i++){
            if (target == matrix[i][0]) {
                return true;
            }
            if (target > matrix[i][0]){
                row = i;
            } else {
                break;
            }
            int left = 0;
            int right = matrix[0].size() - 1;
            while (left <= right){
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                } else if (matrix[row][mid] > target){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
