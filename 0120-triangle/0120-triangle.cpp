class Solution {
private:
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left = solve(triangle, i+1, j, dp);
        int right = solve(triangle, i+1, j+1, dp);
        return dp[i][j] = triangle[i][j] + min(left, right);
    }
    int solveTab(vector<vector<int>>& triangle){
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                int left = dp[i+1][j];
                int right = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(left, right);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveTab(triangle);
    }
};