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
    TreeNode* createMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& nodeToParent){
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val==start) res = temp;
            if(temp->left){
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int BurnTree(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent){
        int ans = 0;
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root]=true;
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    flag = true;
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    flag = true;
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                    flag = true;
                    q.push(nodeToParent[temp]);
                    visited[nodeToParent[temp]]=true;
                }
            }
            if(flag==true) ans++;
        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createMapping(root, start, nodeToParent);
        return BurnTree(targetNode, nodeToParent);
    }
};