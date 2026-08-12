/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void nodeCount(Node* root, int& cnt){
        if(root==NULL) return;
        cnt++;
        nodeCount(root->left, cnt);
        nodeCount(root->right, cnt);
    }
    
    bool isCBT(Node* root, int i, int cnt){
        if(root==NULL) return true;
        if(i>=cnt) return false;

        bool left = isCBT(root->left, 2*i+1, cnt);
        bool right = isCBT(root->right, 2*i+2, cnt);
        return (left&&right);
    }
    
    bool(maxOrder(Node* root)){
        if(root->left == NULL && root->right==NULL) return true;
        if(root->right==NULL) return root->data > root->left->data;
        if(root->left && root->right){
            return (root->data > root->left->data && root->data > root->right->data && maxOrder(root->left) && maxOrder(root->right));
        }
    }
  public:
    bool isHeap(Node* tree) {
        int cnt = 0;
        nodeCount(tree, cnt);
        return (isCBT(tree, 0, cnt) && maxOrder(tree));
        
    }
};