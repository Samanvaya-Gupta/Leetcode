class Solution {
  private:
    int solve(vector<int>& wt, vector<int>& val, int index, int capacity, vector<vector<int>>& dp){
        if(index==0){
            if(wt[index]<=capacity){
                return val[index];
            }
            else return 0;
        }
        
        if(dp[index][capacity]!=-1) return dp[index][capacity];
        
        int include = 0;
        if(wt[index]<=capacity){
            include = val[index] + solve(wt, val, index-1, capacity-wt[index], dp);
        }
        
        int exclude = solve(wt, val, index-1, capacity, dp);
        return dp[index][capacity] = max(include, exclude);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(wt, val, n-1, W, dp);
    }
};