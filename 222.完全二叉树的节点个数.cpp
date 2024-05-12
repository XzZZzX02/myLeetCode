/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include "leetcode.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
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
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int left_depth = 0, right_depth = 0;
        TreeNode *left = root->left, *right = root->right;
        while (left) {
            left_depth++;
            left = left->left;
        }
        while (right) {
            right_depth++;
            right = right->right;
        }
        if (left_depth == right_depth) {
            return (2 << left_depth) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end
