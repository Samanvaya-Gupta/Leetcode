class Solution {
private:
    void addSoln(vector<vector<string>>& ans, vector<vector<int>> board, int n){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                if(board[i][j]==0) s.push_back('.');
                else s.push_back('Q');
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> board, int n){
        int x = row, y=col;
        while(y>=0){
            if(board[x][y]==1) return false;
            y--;
        }
        x = row, y = col;
        while(x>=0 && y>=0){
            if(board[x][y]==1) return false;
            y--;
            x--;
        }
        x = row, y = col;
        while(x<n && y>=0){
            if(board[x][y]==1) return false;
            y--;
            x++;
        }
        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<vector<int>> board, int n){
        if(col == n){
            addSoln(ans, board, n);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col]=1;
                solve(col+1, ans, board, n);
                board[row][col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        solve(0, ans, board, n);
        return ans;
    }
};