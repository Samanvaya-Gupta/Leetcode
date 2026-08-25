class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // pal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;

            for(int j = i; j < n; j++) {
                if(pal[i][j]) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};