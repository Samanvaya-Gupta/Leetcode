class Solution {
  private:
    bool isSafe(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& maze, int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]!=1 && maze[x][y]==1) return true;
        return false;
    }
    void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, vector<vector<int>>& visited, string path){
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[i][j] = 1;
        if(isSafe(i+1, j, visited, maze, n)){
            solve(i+1, j, maze, n, ans, visited, path+'D');
        }
        if(isSafe(i, j-1, visited, maze, n)){
            solve(i, j-1, maze, n, ans, visited, path+'L');
        }
        if(isSafe(i, j+1, visited, maze, n)){
            solve(i, j+1, maze, n, ans, visited, path+'R');
            
        }
        if(isSafe(i-1, j, visited, maze, n)){
            solve(i-1, j, maze, n, ans, visited, path+'U');
            
        }
        visited[i][j] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(maze[0][0]==0) return ans;
        string path = "";
        solve(0,0,maze,n,ans,visited,path);
        return ans;
    }
};