class Solution {
private:
    bool solve(vector<int>& nums, int n, int index, int targetSum, vector<vector<int>>& dp){
        if(index>=n) return false;
        if(targetSum==0) return true;
        if(targetSum<0) return false;
        if(dp[index][targetSum]!=-1){
            if(dp[index][targetSum]==0) return false;
            else return true;
        }
        bool include = false;
        if(targetSum - nums[index] >= 0) include = solve(nums, n, index+1, targetSum-nums[index], dp);
        bool exclude = solve(nums, n, index+1, targetSum, dp);
        bool ans = (include || exclude);
        if(ans) dp[index][targetSum] = 1;
        else dp[index][targetSum] = 0;
        return (include || exclude);
    }

    bool solveOpt(vector<int>& nums, int n, int targetSum){
        vector<int> curr(targetSum+1, 0);
        curr[0] = 1;
        for(int index = 1; index<n; index++){
            for(int w = targetSum; w>=0; w--){
                int include = 0;
                if(w - nums[index] >= 0) include = curr[w - nums[index]];
                int exclude = curr[w];
                if(include == 1 || exclude == 1) curr[w] = 1;
                else curr[w] = 0;
            }
        }
        if(curr[targetSum] == 1) return true;
        return false; 
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2==1) return false;

        int targetSum = sum/2;
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
        return solveOpt(nums, n, targetSum);
    }
};