class Solution {
private:
    int solve(int n, int k, int target, int m, vector<vector<vector<int>>>& dp){
        if(n==0 && target == 0) return 1;
        else if(n==0 && target>0) return 0;
        if(target<0) return 0;
        if(n==1){
            if(target >= 1 && target <= k) return 1;
            else return 0;
        }
        if(dp[n][k][target]!=-1) return dp[n][k][target];
        long long include = 0;
        for(int i=1; i<=k; i++){
            include += solve(n-1, k, target-i, m, dp);
        }
        return dp[n][k][target] = include % m;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n==1 && target > k) return 0;
        else if(n==1 && target<=k) return 1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, -1)));
        int m = pow(10, 9) + 7;
        return solve(n, k, target, m, dp)%m;
    }
};