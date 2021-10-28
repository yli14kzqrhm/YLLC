class Solution {
public:
    vector<vector<bool>> done;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int compcolor = grid[row][col];
        done.assign(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, row, col, color, compcolor);
        
        return grid;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, int color, int compcolor) {
        if ((row < 0) || 
            (row >= grid.size()) || 
            (col < 0) || 
            (col >= grid[0].size()) || 
            (grid[row][col] != compcolor) || 
            (done[row][col] == true)) {
            return ;
        }
        
        done[row][col] = true;
        
        if ((row == 0) || 
            (row == grid.size() - 1) || 
            (col == 0) || 
            (col == grid[0].size() - 1)) {
            grid[row][col] = color;
        } else if ((row > 0) && 
                   (grid[row-1][col] != compcolor) && 
                   (done[row-1][col] == false)) {
            grid[row][col] = color;
        } else if ((row < grid.size() - 1) && 
                   (grid[row+1][col] != compcolor) &&
                   (done[row+1][col] == false )) {
            grid[row][col] = color;
        } else if ((col > 0) && 
                   (grid[row][col-1] != compcolor) &&
                   (done[row][col-1] == false)) {
            grid[row][col] = color;
        } else if ((col < grid[0].size() - 1) && 
                   (grid[row][col+1] != compcolor) &&
                   (done[row][col+1] == false)) {
            grid[row][col] = color;
        }   
        
        dfs(grid, row+1, col, color, compcolor);
        dfs(grid, row-1, col, color, compcolor);
        dfs(grid, row, col+1, color, compcolor);
        dfs(grid, row, col-1, color, compcolor);
    }
};