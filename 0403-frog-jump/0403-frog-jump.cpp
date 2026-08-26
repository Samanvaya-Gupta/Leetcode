class Solution {
private:
    bool solve(int index, int lastJump,
               vector<int>& stones,
               unordered_map<int,int>& pos,
               vector<vector<int>>& dp) {

        int n = stones.size();

        if(index == n - 1)
            return true;

        if(dp[index][lastJump] != -1)
            return dp[index][lastJump];

        int currPos = stones[index];

        for(int jump = lastJump - 1; jump <= lastJump + 1; jump++) {

            if(jump <= 0)
                continue;

            int nextPos = currPos + jump;

            if(pos.find(nextPos) != pos.end()) {

                int nextIndex = pos[nextPos];

                if(solve(nextIndex, jump, stones, pos, dp))
                    return dp[index][lastJump] = 1;
            }
        }

        return dp[index][lastJump] = 0;
    }

public:
    bool canCross(vector<int>& stones) {

        int n = stones.size();

        if(n == 1)
            return true;

        if(stones[1] != 1)
            return false;

        unordered_map<int,int> pos;

        for(int i = 0; i < n; i++)
            pos[stones[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(1, 1, stones, pos, dp);
    }
};