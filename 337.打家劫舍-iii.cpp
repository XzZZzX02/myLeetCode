/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    pair<int, int> rob_(TreeNode* cur) {
        if (!cur) {
            return {0, 0};
        }
        auto [lf, ls] = rob_(cur->left);
        auto [rf, rs] = rob_(cur->right);
        return {max(lf, ls) + max(rf, rs), cur->val + lf + rf};
    }
    int rob(TreeNode* root) {
        auto res = rob_(root);
        return max(res.first, res.second);
    }
};
// @lc code=end
