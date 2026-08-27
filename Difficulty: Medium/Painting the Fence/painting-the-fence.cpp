class Solution {
  private:
    int solve(int n, int k, vector<int>& dp){
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (k-1)* (solve(n-1, k, dp) + solve(n-2, k, dp));
    }
  public:
    int countWays(int n, int k) {
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};