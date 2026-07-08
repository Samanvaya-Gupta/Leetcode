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
    void createMapping(vector<int>& inorder, map<int,int>& nodetoIndex, int n){
        for(int i=0; i<n; i++){
            nodetoIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd, int n, map<int,int>& nodetoIndex){
        if(index>=n || inorderStart > inorderEnd) return NULL;

        int el = preorder[index++];
        TreeNode* root = new TreeNode(el);
        int posn = nodetoIndex[el];

        root->left = solve(inorder, preorder, index, inorderStart, posn-1, n, nodetoIndex);
        root->right = solve(inorder, preorder, index, posn+1, inorderEnd, n, nodetoIndex);
        
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int index = 0;
        map<int, int> nodetoIndex;
        createMapping(inorder, nodetoIndex, n);
        TreeNode* ans = solve(inorder, preorder, index, 0, n-1, n, nodetoIndex);
        return ans;
    }
};