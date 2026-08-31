class Solution {
  private:
    bool solve(vector<int>& nums, int n, int index, int targetSum, vector<vector<int>>& dp){
        if(index>=n && targetSum!=0) return false;
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
        return ans;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, n, 0, sum, dp);
    }
};