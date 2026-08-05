/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void solve(Node* root, vector<int>& inorder){
        if(root==NULL) return;
        solve(root->left, inorder);
        inorder.push_back(root->data);
        solve(root->right, inorder);
    }
  public:
    Node *flattenBST(Node *root) {
        // code here
        vector<int> inorder;
        solve(root, inorder);
        Node* r = new Node(inorder[0]);
        Node* temp = r;
        for(int i=1; i<inorder.size(); i++){
            temp->left = NULL;
            temp->right = new Node(inorder[i]);
            temp = temp->right;
        }
        return r;
    }
};