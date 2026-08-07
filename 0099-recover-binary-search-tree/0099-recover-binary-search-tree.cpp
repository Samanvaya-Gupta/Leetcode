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
TreeNode* first;
TreeNode* last;
TreeNode* previous;
TreeNode* middle;
class Solution {
private:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);

        if(previous!=NULL && root->val<previous->val){
            if(first==NULL){
                first = previous;
                middle = root;
            }
            else last = root;
        }
        previous = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        previous = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};