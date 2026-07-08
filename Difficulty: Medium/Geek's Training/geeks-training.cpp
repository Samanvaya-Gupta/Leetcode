class Solution {
  public:
    int solve(int day, int last, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(day==0){
            int maxi=0;
            for(int task=0; task<3; task++){
                if(task!=last){
                    maxi = max(maxi, mat[0][task]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi = 0;
        for(int task = 0; task<3; task++){
            if(task!=last){
                int pnt = mat[day][task] + solve(day-1, task, mat, dp);
                maxi = max(maxi, pnt);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n-1, 3, mat, dp);
    }
};