/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res;
    enum STATE { UNCOVER, CAMERA, COVER };

public:
    int traverse(TreeNode* t) {
        if (!t) {
            return 2;
        }
        int left = traverse(t->left);
        int right = traverse(t->right);
        if (left == 2 && right == 2) {
            return 0;
        } else if (left == 0 || right == 0) {
            res++;
            return 1;
        } else {
            return 2;
        }
    }
    int minCameraCover(TreeNode* root) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        res = 0;
        if (!traverse(root)) {
            res++;
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0, new TreeNode(0), new TreeNode(0));
    int res = s.minCameraCover(root);
    cout << res << endl;
    return 0;
}
#endif