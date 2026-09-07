class Solution {
  private:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n) return INT_MIN;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int cherries = 0;
        if(j1==j2) cherries = grid[i][j1];
        else cherries = grid[i][j1] + grid[i][j2];
        int best = max(solve(grid, m, n, i+1, j1-1, j2-1, dp), max(solve(grid, m, n, i+1, j1-1, j2, dp), max(solve(grid, m, n, i+1, j1-1, j2+1, dp), max(solve(grid, m, n, i+1, j1, j2-1, dp), max(solve(grid, m, n, i+1, j1, j2, dp), max(solve(grid, m, n, i+1, j1, j2+1, dp), max(solve(grid, m, n, i+1, j1+1, j2-1, dp), max(solve(grid, m, n, i+1, j1+1, j2, dp), solve(grid, m, n, i+1, j1+1, j2+1, dp)))))))));

        return dp[i][j1][j2] = best + cherries;
    }
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(grid, m, n, 0, 0, n-1, dp);
    }
};