/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void createMapping(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent){
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    void solve(TreeNode* target, int k, map<TreeNode*, TreeNode*>& nodeToParent, vector<int>& ans, map<TreeNode*, bool>& visited){
        if(target == NULL) return;
        if(visited[target]) return;
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        visited[target] = true;
        if(target->left){
            solve(target->left, k-1, nodeToParent, ans, visited);
        }
        if(target->right){
            solve(target->right, k-1, nodeToParent, ans, visited);
        }
        if(nodeToParent[target]){
            solve(nodeToParent[target], k-1, nodeToParent, ans, visited);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> nodeToParent;
        createMapping(root, nodeToParent);
        vector<int> ans;
        map<TreeNode*, bool> visited;
        solve(target, k, nodeToParent, ans, visited);
        return ans;
    }
};