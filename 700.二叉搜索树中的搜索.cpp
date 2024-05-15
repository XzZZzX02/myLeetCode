/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 */
#include "leetcode.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val != val && !root->left && !root->right) return nullptr;
        if (root->val == val) return root;
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode* root =
        new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                     new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    int val = 2;
    TreeNode* res = s.searchBST(root, val);
    cout << res << endl;
    return 0;
}
#endif