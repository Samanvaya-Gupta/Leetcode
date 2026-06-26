class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int reqNum = target - nums[i];
            if(mpp.find(reqNum)!= mpp.end()){
                return {mpp[reqNum], i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};