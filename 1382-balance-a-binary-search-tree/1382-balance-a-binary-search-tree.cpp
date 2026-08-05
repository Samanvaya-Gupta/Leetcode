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
    void inorder(TreeNode* root, vector<int>& inordr){
        if(root == NULL) return;
        inorder(root -> left, inordr);
        inordr.push_back(root->val);
        inorder(root -> right, inordr);
    }
    TreeNode* inordertoBST(int s, int e, vector<int> inordr){
        if(s>e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(inordr[mid]);
        root->left = inordertoBST(s, mid-1, inordr);
        root->right = inordertoBST(mid+1, e, inordr);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inordr;
        inorder(root, inordr);
        return inordertoBST(0, inordr.size()-1, inordr);
    }
};