/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int targetSum, bool& ans, vector<int>& path){
        if(root==NULL) return;

        path.push_back(root->val);
        solve(root->left, targetSum, ans, path);
        solve(root->right, targetSum, ans, path);

        int sum = 0;
        int n = path.size();
        for(int i=n-1; i>=0; i--){
            sum+=path[i];
        }
        if(sum==targetSum && (root->left==NULL && root->right==NULL)) {
            ans=true;
            return;
        }
        path.pop_back();
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        bool ans=false;
        solve(root, targetSum, ans, path);
        return ans;
    }
};