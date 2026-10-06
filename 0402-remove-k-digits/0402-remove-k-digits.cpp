class Solution {
private:
    void reverse(string& s){
        int n = s.length();
        int i=0, j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k==n) return "0";
        stack<char> s;
        int i=0;
        for(int i=0; i<n; i++){
            while (!s.empty() && k!=0 && ((num[i] - '0') < (s.top() - '0'))) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k!=0 && !s.empty()){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.length()!=0 && ans[ans.length()-1]=='0') ans.pop_back();
        if(ans.length()==0) return "0";
        reverse(ans);
        return ans;
    }
};