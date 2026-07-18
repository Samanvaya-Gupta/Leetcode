class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = customers[0][0];
        long long wt = 0;
        int n = customers.size();
        for(int i=0; i<n; i++){
            if(time<customers[i][0]) time = customers[i][0];
            time += customers[i][1];
            wt += time - customers[i][0];
        }
        return (double)wt/n;
    }
};