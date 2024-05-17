/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key == root->val) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (!root->left) {
                TreeNode* res = root->right;
                delete root;
                return res;
            }
            if (!root->right) {
                TreeNode* res = root->left;
                delete root;
                return res;
            }
            TreeNode* node = root->right;
            while (node->left) node = node->left;
            node->left = root->left;
            TreeNode* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end
