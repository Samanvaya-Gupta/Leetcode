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
// private:
//     void width(TreeNode* root){
//         if(root==NULL) return;
        
//     }
    public:
        int widthOfBinaryTree(TreeNode* root) {
            int ans = 0;
            if(root == NULL) return 0;
            queue<pair<TreeNode*, long long>> q;
            q.push(make_pair(root, 0));
            while(!q.empty()){
                int n = q.size();
                int min = q.front().second;
                int first, last;
                for(int i=0; i<n; i++){
                    long long curr = q.front().second - min;
                    TreeNode* temp = q.front().first;
                    q.pop();
                    if(i==0) first = curr;
                    if(i==n-1) last = curr;
                    if(temp->left) q.push({temp->left, curr*2 + 1});
                    if(temp->right) q.push({temp->right, curr*2 + 2});
                }
                ans = max(ans, last-first+1);
            }
            return ans;
        }
};