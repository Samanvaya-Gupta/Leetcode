/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  private:
    void solve(Node* root, int k, int& ans){
        if(root==NULL) return;
        if(root->data == k){
            ans = k;
            return;
        }
        if(root->data < k){
            ans = max(ans, root->data);
            solve(root->right, k, ans);
        }
        else if(root->data > k){
            solve(root->left, k, ans);
        }
    }
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};