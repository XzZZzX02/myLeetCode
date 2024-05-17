/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */
#include <iostream>

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
    int pre = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root->right);
        pre += root->val;
        root->val = pre;
        convertBST(root->left);
        return root;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode* root =
        new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2)),
                     new TreeNode(6, new TreeNode(5), new TreeNode(7)));
    TreeNode* res = s.convertBST(root);
    cout << res << endl;
    return 0;
}
#endif