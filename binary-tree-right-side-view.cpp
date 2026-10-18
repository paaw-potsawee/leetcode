//https://leetcode.com/problems/binary-tree-right-side-view/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode left, TreeNode right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void search(TreeNode* root, int* mDepth, int cDepth, vector<int>& res) {
        if (root == nullptr) return;
        if (cDepth >= *mDepth) {
            res.push_back(root->val);
            (*mDepth)++;
        }
        if (root->right != nullptr) {
            search(root->right, mDepth, cDepth + 1, res);
        }
        if (root->left != nullptr) {
            search(root->left, mDepth, cDepth + 1, res);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result = {};
        int mDepth = 0;
        int* ptr = &mDepth;
        search(root, ptr, 0, result);
        return result;
    }
};
