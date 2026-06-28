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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> rightNode;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int h = temp.second;
            if(rightNode.find(h)==rightNode.end()){
                rightNode[h] = frontNode->val;
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, h+1));
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left, h+1));
            }
        }
        for(auto i: rightNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};