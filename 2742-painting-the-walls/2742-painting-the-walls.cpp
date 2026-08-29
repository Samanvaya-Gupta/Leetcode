class Solution {
private:
    int solve(vector<int>& cost, vector<int>& time, int n,
          int index, int coverage, vector<vector<int>>& dp) {


            if(coverage >= n)
                return 0;

            if(index < 0)
                return INT_MAX;

            if(dp[index][coverage] != -1) return dp[index][coverage];

            int include = solve(cost, time, n, index - 1,
                                coverage + time[index] + 1, dp);

            if(include != INT_MAX)
                include += cost[index];

            int exclude = solve(cost, time, n, index - 1,
                                coverage, dp);

            return dp[index][coverage] = min(include, exclude);
        }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(cost, time, n, n-1, 0, dp);
    }
};