#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int row = 0; row < 9; row++) {
            unordered_set<char> rows;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (rows.count(board[row][col])) {
                    return false;
                }
                rows.insert(board[row][col]);
            }
        }
        for (int col = 0; col < 9; col++) {
            unordered_set<char> columns;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (columns.count(board[row][col])) {
                    return false;
                }
                columns.insert(board[row][col]);
            }
        }
        for (int grid = 0; grid < 9; grid++) {
            unordered_set<char> grids;
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    int startRow = (grid / 3) * 3 + row;
                    int startCol = (grid % 3) * 3 + col;
                    if (board[startRow][startCol] == '.') {
                        continue;
                    }
                    if (grids.count(board[startRow][startCol])) {
                        return false;
                    }
                    grids.insert(board[startRow][startCol]);
                }
            }
        }

        return true;
    }
};

