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
public:
int ans;
    void oneRootSum(TreeNode* root, int targetSum) {
        if (!root) return;
        if (targetSum == root->val) {
            ans++;
        }
        oneRootSum(root->left, targetSum - root->val);
        oneRootSum(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            oneRootSum(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};