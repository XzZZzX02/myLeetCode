/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include "leetcode.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *root, int target) {
        target -= root->val;
        if (!root->left && !root->right && !target) {
            return true;
        }
        if (root->left) {
            if (dfs(root->left, target)) return true;
        }
        if (root->right) {
            if (dfs(root->right, target)) return true;
        }
        target += root->val;
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum);
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    bool res = s.hasPathSum(root, 22);
    cout << res << endl;
    return 0;
}
#endif