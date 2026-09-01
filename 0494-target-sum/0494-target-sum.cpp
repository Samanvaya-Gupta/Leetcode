class Solution {
private:
    int solve(vector<int>& nums, int index, int target,
              int total, vector<vector<int>>& dp) {

        if(index == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        if(target < -total || target > total)
            return 0;

        if(dp[index][target + total] != -1)
            return dp[index][target + total];

        int plus = solve(nums, index + 1,
                         target - nums[index],
                         total, dp);

        int minus = solve(nums, index + 1,
                          target + nums[index],
                          total, dp);

        return dp[index][target + total] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;
        for(int x : nums)
            total += x;

        if(target > total || target < -total)
            return 0;

        vector<vector<int>> dp(
            n, vector<int>(2 * total + 1, -1)
        );

        return solve(nums, 0, target, total, dp);
    }
};