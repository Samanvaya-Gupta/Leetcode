class Solution {
private:
    int solve(string& word1, string& word2, int n1, int n2, int i, int j, vector<vector<int>>& dp){
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i;
        if(word1[i]==word2[j]) return solve(word1, word2, n1, n2, i+1, j+1, dp);
        if(dp[i][j]!=-1) return dp[i][j];
        int insert = 1 + solve(word1, word2, n1, n2, i, j+1, dp);
        int del = 1 + solve(word1, word2, n1, n2, i+1, j, dp);
        int replace = 1 + solve(word1, word2, n1, n2, i+1, j+1, dp);
        return dp[i][j] = min(insert, min(del, replace));
    }
    int solveTab(string& word1, string& word2){
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        for(int i = 0; i <= n1; i++) {
            dp[i][n2] = n1 - i;
        }

        for(int j = 0; j <= n2; j++) {
            dp[n1][j] = n2 - j;
        }


        for(int i=n1-1; i>=0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                if(word1[i]==word2[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    int insert = 1 + dp[i][j+1];
                    int del = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        if(word1==word2) return 0;
        //return solve(word1, word2, n1, n2, 0, 0, dp);
        return solveTab(word1, word2);
    }
};