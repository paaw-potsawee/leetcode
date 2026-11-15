// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
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
    void search(TreeNode* root, int mVal, int& count) {
        if ((*root).val >= mVal) count++;
        if (root->left != nullptr) search(root->left, max(mVal, root->val), count);
        if (root->right != nullptr) search(root->right, max(mVal, root->val), count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        search(root, root->val, count);
        return count;
    }
};
