class Solution {
    // Let m be the number of rows in the matrix
    // Let n be the number of colums in the matrix
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int left = 0;
        int right = (matrix.size() * matrix[0].size()) - 1;
        while (left <= right){
            int middle = left + (right - left) / 2;
            int row = middle / matrix[0].size();
            int column = middle % matrix[0].size();
            if (target == matrix[row][column]){
                return true;
            } else if (target > matrix[row][column]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};
