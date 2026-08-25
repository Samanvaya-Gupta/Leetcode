class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val){
        int n = board[0].size();
        char ch = val + '0';
        for(int i=0; i<n; i++){
            if(i != col && board[row][i]==ch) return false;
            if(i != row && board[i][col]==ch) return false;
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if((r != row || c != col) && board[r][c] == ch)
                return false;
            }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int num = 0;
                char val = board[i][j];
                if(val=='.') continue;
                else num = val - '0';
                if(!isSafe(i, j, board, num)) return false;
            }
        }
        return true;
    }
};