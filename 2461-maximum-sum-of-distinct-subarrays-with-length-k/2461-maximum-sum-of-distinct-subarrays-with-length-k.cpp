class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int l = 0;
        long long sum = 0;
        long long ans = 0;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            mp[nums[r]]++;
            while(mp[nums[r]]>1 || r-l+1>k){
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1==k) ans = max(ans, sum);
        }
        return ans;
    }
};