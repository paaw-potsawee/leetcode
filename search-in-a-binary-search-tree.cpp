// https://leetcode.com/problems/search-in-a-binary-search-tree/description/
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
    TreeNode* search(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) {
            return root;
        }
        if (root->val > val) {
            return search(root->left, val);
        }
        return search(root->right, val);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};
