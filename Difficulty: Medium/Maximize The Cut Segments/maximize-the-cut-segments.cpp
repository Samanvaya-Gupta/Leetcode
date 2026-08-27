class Solution {
  private:
    int solve(int n, vector<int>& cuts, vector<int>& dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        int maxi = INT_MIN;
        for(int i=0; i<cuts.size(); i++){
            int ans = solve(n-cuts[i], cuts, dp);
            if(ans!=INT_MIN){
                maxi = max(ans+1, maxi);
            }
        }
        return dp[n] = maxi;
    }
  public:
    int maximizeCuts(int n, int x, int y, int z) {
        // code here
        vector<int> dp(n+1, -1);
        vector<int> cuts = {x,y,z};
        int ans = solve(n, cuts, dp);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};