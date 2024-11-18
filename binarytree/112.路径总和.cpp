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
