// https://leetcode.com/problems/delete-node-in-a-bst/
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
    int getMin(TreeNode* root) {
        if (root == nullptr) return 0;
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val > key) {
            // go left
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // go right
            root->right = deleteNode(root->right, key);
        } else {
            // delete

            // no child or left child only
            if (root->right == nullptr) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            // only right child
            if (root->left == nullptr) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            root->val = getMin(root->right);

            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};
