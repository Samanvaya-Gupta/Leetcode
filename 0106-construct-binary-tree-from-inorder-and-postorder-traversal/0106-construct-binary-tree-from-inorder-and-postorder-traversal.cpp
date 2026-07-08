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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index, int inorderStart, int inorderEnd, int n, map<int,int>& nodetoIndex){
        if(index<0 || inorderStart > inorderEnd) return NULL;

        int el = postorder[index--];
        TreeNode* root = new TreeNode(el);
        int posn = nodetoIndex[el];

        root->right = solve(inorder, postorder, index, posn+1, inorderEnd, n, nodetoIndex);
        root->left = solve(inorder, postorder, index, inorderStart, posn-1, n, nodetoIndex);
        
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n-1;
        map<int, int> nodetoIndex;
        createMapping(inorder, nodetoIndex, n);
        TreeNode* ans = solve(inorder, postorder, index, 0, n-1, n, nodetoIndex);
        return ans;
    }
};