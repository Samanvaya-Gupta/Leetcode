class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            if(obstacleGrid[i][j]==0) return 1;
            else return 0;
        }
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(obstacleGrid, i-1, j, dp);
        int left = solve(obstacleGrid, i, j-1, dp);
        return dp[i][j] = up+left;
    }

    int solveOpt(vector<vector<int>>& obstacleGrid, int m, int n){
        vector<int> curr(n, 0);
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        curr[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0&&j==0) continue;
                if(obstacleGrid[i][j]==1){
                    curr[j]=0;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i>0) up = curr[j];
                if(j>0) left = curr[j-1];
                curr[j] = up+left;
            }
        }
        return curr[n-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveOpt(obstacleGrid, m, n);
    }
};