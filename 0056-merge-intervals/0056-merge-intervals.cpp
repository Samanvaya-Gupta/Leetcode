class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int i=0;
        vector<vector<int>> ans;
        // while(i<n-1 && intervals[i][1] < intervals[i+1][0]){
        //     ans.push_back(intervals[i]);
        //     i++;
        // }
        while(i<n){   
            vector<int> temp(2);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            while(i<n && intervals[i][0] <= temp[1]){
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
                i++;
            }
            ans.push_back(temp);
        }
        // while(i<n){
        //     ans.push_back(intervals[i]);
        //     i++;
        // }
        return ans;
    }
};