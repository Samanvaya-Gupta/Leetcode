class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        if(m>n) return ans;
        int l=0;
        map<char, int> ms;
        map<char, int> mp;
        for(int i=0; i<m; i++){
            mp[p[i]]++;
        }
        for(int r=0; r<n; r++){
            ms[s[r]]++;
            if(r-l+1==m){
                if(ms==mp) ans.push_back(l);
                ms[s[l]]--;
                if(ms[s[l]]==0) ms.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};