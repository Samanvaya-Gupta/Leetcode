class Solution {
private:
    int solve(int n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int o1 = costs[0] + solve(n, days, costs, index+1, dp);

        int i;
        for(i=index; i<n && days[i]<days[index]+7; i++) continue;

        int o2 = costs[1] + solve(n, days, costs, i, dp);

        for(i=index; i<n && days[i]<days[index]+30; i++) continue;

        int o3 = costs[2] + solve(n, days, costs, i, dp);

        return dp[index] = min(o1, min(o2, o3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(n, days, costs, 0, dp);
    }
};