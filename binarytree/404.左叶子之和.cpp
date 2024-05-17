/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        if (root->left && !root->left->left && !root->left->right) {
            res += root->left->val;
        }
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode *root = new TreeNode(
        1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    int res = s.sumOfLeftLeaves(root);
    cout << res << endl;
    return 0;
}
#endif