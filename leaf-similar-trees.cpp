// https://leetcode.com/problems/leaf-similar-trees/description/

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
    vector<int> leaf = {};
    int ptr = 0;
    void search(TreeNode* root) {
        if (root == nullptr) return;
        auto left = root->left;
        auto right = root->right;
        if (left == nullptr && right == nullptr) {
            leaf.push_back(root->val);
        }
        search(left);
        search(right);
    }
    bool search2(TreeNode* root) {
        if (root == nullptr) return true;
        auto left = root->left;
        auto right = root->right;
        bool res = true;
        if (left == nullptr && right == nullptr) {
            if (ptr >= leaf.size()) res = false;
            else if(root->val != leaf[ptr++]) res = false;
        }
        res = res & search2(left);
        res = res & search2(right);
        return res;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        search(root1);
        return search2(root2) & (ptr == leaf.size());
    }
}
