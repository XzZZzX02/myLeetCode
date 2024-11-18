/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root, long minVal = LONG_MIN,
                    long maxVal = LONG_MAX) {
        if (!root) return true;
        if (root->left &&
            (root->left->val >= root->val || root->left->val <= minVal)) {
            return false;
        }
        if (root->right &&
            (root->right->val <= root->val || root->right->val >= maxVal)) {
            return false;
        }
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};
// @lc code=end
