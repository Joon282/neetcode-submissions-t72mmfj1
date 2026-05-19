class Solution {
    /* 
    Iterate through each point in grid[row][col]
    Check neighbouring points up,down,left,right for land 
    Skip any water nodes 
    When checking neighbour nodes if any adcolsacent node is also land subtract count
    */
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col] == 1){
                    if (row == 0 || grid[row-1][col] == 0) {
                        perimeter++;
                    }
                    if (row == grid.size()-1 || grid[row+1][col] == 0) {
                        perimeter++;
                    }
                    if (col == 0 || grid[row][col-1] == 0) {
                        perimeter++;
                    }
                    if (col == grid[0].size()-1 || grid[row][col+1] == 0) {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};