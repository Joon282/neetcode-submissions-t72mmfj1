class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++){
            std::unordered_set<int> row_set;
            for (int col = 0; col < 9; col++){
                if (board[row][col] == '.'){
                    continue;
                }
                if (row_set.contains(board[row][col]) || !std::isdigit(board[row][col])){
                    return false;
                }
                row_set.insert(board[row][col]);
            }
        }

        for (int col = 0; col < 9; col++){
            std::unordered_set<int> col_set;
            for (int row = 0; row < 9; row++){
                if (board[row][col] == '.'){
                    continue;
                }
                if (col_set.contains(board[row][col]) || !std::isdigit(board[row][col])){
                    return false;
                }
                col_set.insert(board[row][col]);
            }
        }

        for (int square = 0; square < 9; square++){
            std::unordered_set<int> square_set;
            for(int row = 0; row < 3; row++){
                for(int col = 0; col < 3; col++){
                    int startRow = (square / 3) * 3 + row;
                    int startCol = (square % 3) * 3 + col;
                    if (board[startRow][startCol] == '.'){
                        continue;
                    }
                    if (square_set.contains(board[startRow][startCol]) || !std::isdigit(board[startRow][startCol])){
                        return false;
                    }
                    square_set.insert(board[startRow][startCol]);
                }
            }
        }
        return true;
    }
};
