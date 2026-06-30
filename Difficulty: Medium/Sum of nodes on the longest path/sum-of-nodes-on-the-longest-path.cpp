/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
    void solve(Node* root, pair<int,int>& val, pair<int,int>& ans){
        if(root==NULL) return;
        val.second++;
        val.first += root->data;
        if(root->left==NULL && root->right==NULL){
            if(val.second > ans.second){
                ans.first = val.first;
            }
            else if(val.second == ans.second){
                ans.first = max(ans.first, val.first);
            }
            ans.second = max(ans.second, val.second);
            val.second--;
            val.first -= root->data;
            return;
        }
        else{
            solve(root->left, val, ans);
            solve(root->right, val, ans);
        }
        val.second--;
        val.first -= root->data;
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        if(root==NULL) return 0;
        pair<int, int> ans, val = make_pair(0,0);
        solve(root, val, ans);
        return ans.first;
    }
};