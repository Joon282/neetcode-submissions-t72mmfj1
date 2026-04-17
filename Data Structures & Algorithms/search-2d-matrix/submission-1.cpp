class Solution {
    //Loop through from 0 to m-1, m is the number of rows
    //Check if the target is > the val in the first column of each row
    // If the target is > then we go to the next row 
    // If the target is less than the first value of a row
    // Decrement the row & perform binary search where left is the first val in row and right is the last val
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][0] == target){
                return true;
            }
            if (matrix[i][0] < target){
                row = i;
            } else {
                break;
            }
        }
        int size = matrix[0].size() - 1;
        int left = 0;
        int right = size;
        while (left <= right){
            int middle = left + (right - left) / 2;
            if (target == matrix[row][middle]){
                return true;
            } else if (target > matrix[row][middle]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};
