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
    void solve(TreeNode* root, map<int, int>& mp){
        if(root==NULL) return;
        mp[root->val]++;
        solve(root->left, mp);
        solve(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;
        solve(root, mp);
        int cnt=0;
        for(auto p: mp){
            if(p.second>cnt){
                cnt = p.second;
            }
        }
        for(auto p: mp){
            if(p.second==cnt){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};