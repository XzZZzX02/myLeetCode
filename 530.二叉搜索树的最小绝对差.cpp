/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    TreeNode *root =
        new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                     new TreeNode(6, new TreeNode(5), new TreeNode(7)));
    int res = s.getMinimumDifference(root);
    cout << res << endl;
    return 0;
}
#endif