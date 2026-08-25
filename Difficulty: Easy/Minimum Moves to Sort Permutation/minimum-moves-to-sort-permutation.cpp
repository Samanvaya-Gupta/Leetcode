class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        vector<int> ind(n+1,-1);
        for(int i=0; i<n; i++){
            ind[arr[i]] = i;
        }
        int maxuntouched = 1;
        int untouched = 1;
        for(int i=1; i<n; i++){
            if(ind[i]<ind[i+1]) untouched++;
            else untouched = 1;
            maxuntouched = max(maxuntouched, untouched);
        }
        return n-maxuntouched;
    }
};