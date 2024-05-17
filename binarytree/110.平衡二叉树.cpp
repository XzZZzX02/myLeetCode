/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int height(TreeNode *root) {
        if (!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left_height = height(root->left);
        int right_height = height(root->right);
        if ((left_height - right_height) * (left_height - right_height) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
