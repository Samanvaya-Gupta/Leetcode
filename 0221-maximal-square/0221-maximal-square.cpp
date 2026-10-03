class Solution {
private:
    int solve(vector<vector<char>>& matrix, int m, int n){
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 1;
                if(i>0 && j>0){
                    dp[i][j] += min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = solve(matrix, m, n);
        return maxi*maxi;
    }
};