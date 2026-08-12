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
    void nodeCount(TreeNode* root, int& cnt){
        if(root==NULL) return;
        cnt++;
        nodeCount(root->left, cnt);
        nodeCount(root->right, cnt);
    }
    bool isCBT(TreeNode* root, int i, int cnt){
        if(root==NULL) return true;
        if(i>=cnt) return false;

        bool left = isCBT(root->left, 2*i+1, cnt);
        bool right = isCBT(root->right, 2*i+2, cnt);
        return (left&&right);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int cnt = 0;
        nodeCount(root, cnt);
        return isCBT(root, 0, cnt);
    }
};