class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        if(n<=3){
            for(int i=0; i<n; i++){
                ans = max(nums[i], ans);
            }
            return ans;
        }
        int prev = nums[0];
        int prev2=0;
        for(int i=1; i<n-1; i++){
            int curr = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = curr;
        }
        int ans1 = prev;

        prev = nums[1];
        prev2 = 0;
        for(int i=2; i<n; i++){
            int curr = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = curr;
        }
        int ans2 = prev;
        ans = max(ans1, ans2);
        return ans;
    }
};