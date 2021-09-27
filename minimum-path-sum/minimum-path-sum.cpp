class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if ((row == 1) && (col == 1)) {
            return grid[0][0];
        }
        vector<vector<int>> dp(row, vector<int>(col,0));
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i]; 
        }
        
        if (row == 1) {
            return dp[0][col-1];
        }
        
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        if (col == 1) {
            return dp[row-1][0];
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[row-1][col-1];
    }
};