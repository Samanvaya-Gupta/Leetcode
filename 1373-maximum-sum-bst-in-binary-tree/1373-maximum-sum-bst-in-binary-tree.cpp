class Solution {
private:
    class NodeValue {
    public:
        int maxNode, minNode, nodeSum;

        NodeValue(int maxi, int mini, int sum) {
            maxNode = maxi;
            minNode = mini;
            nodeSum = sum;
        }
    };

    int ans = 0;

    NodeValue largestBST(TreeNode* root) {
        if (root == NULL) {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        auto left = largestBST(root->left);
        auto right = largestBST(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {

            int sum = left.nodeSum + right.nodeSum + root->val;

            // IMPORTANT
            ans = max(ans, sum);

            return NodeValue(
                max(root->val, right.maxNode),
                min(root->val, left.minNode),
                sum
            );
        }

        return NodeValue(INT_MAX, INT_MIN, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        largestBST(root);
        return ans;
    }
};