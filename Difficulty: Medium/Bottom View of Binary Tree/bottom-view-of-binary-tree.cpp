/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int h = temp.second;
            topNode[h] = frontNode->data;
            if(frontNode->left){
                q.push(make_pair(frontNode->left, h-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, h+1));
            }
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};