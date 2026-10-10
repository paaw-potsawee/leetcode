// https://leetcode.com/problems/maximum-depth-of-binary-tree/description
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    int max(int d1, int d2) {
        return d1 > d2 ? d1 : d2;
    }
    int traverse(TreeNode* node, int depth) {
        if(node == nullptr) {
            return depth;
        }
        int d1 = traverse(node->left, depth + 1);
        int d2 = traverse(node->right, depth + 1);
        return max(d1, d2);
    }
public:
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }
};
