class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] < end) {
                count++;

                // keep the interval having smaller ending point
                end = min(end, intervals[i][1]);
            }
            else {
                end = intervals[i][1];
            }
        }

        return count;
    }
};