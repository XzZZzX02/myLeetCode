/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    TreeNode *prev = nullptr;
    int count = 0;
    int max_count = 0;
    vector<int> res;

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (!prev) {
            count = 1;
        } else if (root->val == prev->val) {
            count++;
        } else {
            count = 1;
        }
        prev = root;
        if (count == max_count) {
            res.push_back(root->val);
        } else if (count > max_count) {
            max_count = count;
            res.clear();
            res.push_back(root->val);
        }
        inorder(root->right);
        return;
    }

public:
    vector<int> findMode(TreeNode *root) {
        if (!root) return res;
        count = 0;
        max_count = 0;
        prev = nullptr;
        res.clear();
        inorder(root);
        return res;
    }
};
// @lc code=end
