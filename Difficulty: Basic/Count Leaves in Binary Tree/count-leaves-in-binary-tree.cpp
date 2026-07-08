/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  private:
    void solve(Node* root, int& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans++;
            return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int ans = 0;
        if(root==NULL) return ans;
        solve(root, ans);
        return ans;
    }
};