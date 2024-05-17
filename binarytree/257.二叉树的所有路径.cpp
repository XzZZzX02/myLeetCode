/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(TreeNode* root, vector<int>& path, vector<string>& res) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            res.push_back(s);
            return;
        }
        if (root->left) {
            dfs(root->left, path, res);
            path.pop_back();
        }
        if (root->right) {
            dfs(root->right, path, res);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        dfs(root, path, res);
        return res;
    }
};
// @lc code=end
