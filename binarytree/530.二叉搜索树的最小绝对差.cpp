/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int> nums;
    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        if (!root) return 0;
        nums.clear();
        dfs(root);
        int res = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] >= 0) {
                res = min(res, nums[i] - nums[i - 1]);
            } else {
                res = min(res, nums[i - 1] - nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
